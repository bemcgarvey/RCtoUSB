#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "satellite.h"
#include "leds.h"
#include "system.h"

volatile bool packetComplete = false;
volatile uint8_t activeBuffer = 1;
volatile uint8_t rxTimerTicks;
volatile DataPacket rxBuffer[2];

volatile bool packetValid = false;
volatile uint8_t bytesReceived = 0;
volatile uint8_t *oddBuffPtr;
volatile uint8_t *evenBuffPtr;

void initSat(void) {
    //setup USART1
    RCSTA1bits.SPEN = 0;
    TXSTA1bits.BRGH = 1;
    BAUDCON1bits.BRG16 = 1;
    SPBRGH1 = 103 >> 8;
    SPBRG1 = 103; //115200 baud
    IPR1bits.RC1IP = 0;
    PIE1bits.RC1IE = 1;
    RCSTA1bits.SPEN = 1;
    satPowerOn();
    rxTimerTicks = 0;
    RCSTA1bits.CREN = 1;
}

void bindSat(int8_t pulses) {
    uint8_t rx;
    INTCONbits.GIEH = 0;
    RCSTA1bits.SPEN = 0;
    RCSTA1bits.CREN = 0;
    led2On();
    satPowerOff();
    __delay_ms(500);
    LATCbits.LATC7 = 1;
    TRISCbits.TRISC7 = 0;
    satPowerOn();
    __delay_ms(50);
    for (char i = 0; i < pulses; ++i) {
        LATCbits.LATC7 = 0;
        __delay_us(118);
        LATCbits.LATC7 = 1;
        __delay_us(123);
    }
    TRISCbits.TRISC7 = 1;
    RCSTA1bits.CREN = 1;
    RCSTA1bits.SPEN = 1;
    //Wait until we receive a full packet to confirm bind
    int8_t rxCount = sizeof (DataPacket);
    while (rxCount) {
        if (PIR1bits.RC1IF) {
            rx = RCREG1;
            --rxCount;
        }
        if (PORTBbits.RB0 == 0) {
            __delay_ms(100);
            break;
        }
    }
    led2Off();
    rxTimerTicks = 0;
    INTCONbits.GIEH = 1;
}

bool satPowered(void) {
    if (LATCbits.LATC0 == 1) {
        return true;
    } else {
        return false;
    }
}

void handleRxInterrupt(void) {
    uint8_t rx;
    if (rxTimerTicks > 2) {
        bytesReceived = 0;
        packetValid = true;
        oddBuffPtr = rxBuffer[activeBuffer].bytes;
        evenBuffPtr = oddBuffPtr + 1;
    }
    rxTimerTicks = 0;
    if (RCSTAbits.OERR) {
        RCSTAbits.CREN = 0;
        packetValid = false;
        bytesReceived = 0;
        oddBuffPtr = rxBuffer[activeBuffer].bytes;
        evenBuffPtr = oddBuffPtr + 1;
        RCSTAbits.CREN = 1;
        return;
    }
    if (RCSTAbits.FERR) {
        packetValid = false;
    }
    rx = RCREG1;
    if (bytesReceived & 1) {
        *oddBuffPtr = rx;
        oddBuffPtr += 2;
    } else {
        *evenBuffPtr = rx;
        evenBuffPtr += 2;
    }
    ++bytesReceived;
    if (bytesReceived == sizeof(DataPacket)) {
        if (packetValid) {
            packetComplete = true;
            activeBuffer ^= 1;
        }
        bytesReceived = 0;  
        oddBuffPtr = rxBuffer[activeBuffer].bytes;
        evenBuffPtr = oddBuffPtr + 1;
    }
}