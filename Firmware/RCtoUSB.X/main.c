#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "system.h"
#include "usb_device.h"
#include "usb_device_hid.h"
#include "joystick.h"
#include "timers.h"
#include "leds.h"
#include "satellite.h"

volatile uint8_t buttonCountdown = 0;
volatile bool buttonPressed = false;

void main(void) {
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    USBDeviceInit();
    USBDeviceAttach();
    __delay_ms(1000);
    initSat();
    while (1) {
#if defined(USB_POLLING)
        USBDeviceTasks();
#endif
        //Application specific tasks
        JoystickTasks();
        if (systemTimerTicks >= 1000) {
            led1Toggle();
            systemTimerTicks = 0;
        }
        if (buttonPressed) {
            buttonPressed = false;
            led1Off();
            bindSat(DSM2_INTERNAL_11MS);
        }
    }
}

void __interrupt(high_priority) highISR(void) {
#if defined(USB_INTERRUPT)
    if (PIR2bits.USBIF) {
        USBDeviceTasks();
    }
#endif
    if (PIR3bits.TMR4IF) {
        ++systemTimerTicks;
        if (buttonCountdown) {
            --buttonCountdown;
            if (buttonCountdown == 0 && PORTBbits.RB0 == 0) {
                buttonPressed = true;
            }
        }
        PIR3bits.TMR4IF = 0;
    }
    if (INTCONbits.INT0IF) {
        buttonCountdown = 20;
        buttonPressed = false;
        INTCONbits.INT0IF = 0;
    }
}

void __interrupt(low_priority) lowISR(void) {
    handleRxInterrupt();
}