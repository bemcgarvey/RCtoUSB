#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "satellite.h"
#include "leds.h"
#include "system.h"


void initSat(void) {
    satPowerOn();
}

void bindSat(int8_t pulses) {
    led2On();
    INTCONbits.GIEH = 0;
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
    led2Off();
    INTCONbits.GIEH = 1;
}

bool satPowered(void) {
    if (LATCbits.LATC0 == 1) {
        return true;
    } else {
        return false;
    }
}
