#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "system.h"
#include "usb_device.h"
#include "joystick.h"
#include "timers.h"
#include "leds.h"
#include "satellite.h"

volatile uint8_t debounceCount;
volatile int buttonTime;
#define DEBOUNCE_TIME   20
#define SHORT_PRESS     960
#define LONG_PRESS      3960   //4 seconds with the 2 * 20ms debounce times

volatile enum {
    BUTTON_IDLE = 0, DEBOUNCE_DOWN = 1, BUTTON_TIMING = 2, DEBOUNCE_UP = 3, BUTTON_PRESSED = 4
} buttonState = BUTTON_IDLE;

void main(void) {
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    USBDeviceInit();
    USBDeviceAttach();
    __delay_ms(1000);
    initSat();
    while (1) {
        JoystickTasks();
        if (packetCount == 90) {
            packetCount = 0;
            led1Toggle();
        }
        if (buttonState == BUTTON_PRESSED) {
            buttonState = BUTTON_IDLE;
            led1Off();
            if (buttonTime > LONG_PRESS) {
                satPowerOff();
                __delay_ms(1000);
                satPowerOn();
            } else if (buttonTime > SHORT_PRESS) {
                bindSat(DSMX_INTERNAL_11MS);
            } else {
                bindSat(DSM2_INTERNAL_11MS);
            }
        }
    }
}

void __interrupt(high_priority) highISR(void) {
    if (PIR2bits.USBIF) {
        USBDeviceTasks();
    }
    if (PIR3bits.TMR4IF) {
        ++systemTimerTicks;
        ++rxTimerTicks;
        if (buttonState == DEBOUNCE_DOWN) {
            --debounceCount;
            if (debounceCount == 0) {
                if (PORTBbits.RB0 == 0) {
                    buttonTime = 0;
                    INTCON2bits.INTEDG0 = 1;
                    buttonState = BUTTON_TIMING;
                } else {
                    buttonState = BUTTON_IDLE;
                    INTCON2bits.INTEDG0 = 0;
                }
            }
        } else if (buttonState == BUTTON_TIMING) {
            ++buttonTime;
        } else if (buttonState == DEBOUNCE_UP) {
            --debounceCount;
            if (debounceCount == 0) {
                if (PORTBbits.RB0 == 1) {
                    buttonState = BUTTON_PRESSED;
                } else {
                    buttonState = BUTTON_IDLE;
                }
                INTCON2bits.INTEDG0 = 0;
            }
        }
        PIR3bits.TMR4IF = 0;
    }
    if (INTCONbits.INT0IF) {
        if (buttonState == BUTTON_IDLE) {
            buttonState = DEBOUNCE_DOWN;
            debounceCount = DEBOUNCE_TIME;
        } else if (buttonState == BUTTON_TIMING) {
            buttonState = DEBOUNCE_UP;
            debounceCount = DEBOUNCE_TIME;
        }
        INTCONbits.INT0IF = 0;
    }
}

void __interrupt(low_priority) lowISR(void) {
    handleRxInterrupt();
}