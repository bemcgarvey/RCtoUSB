#include <xc.h>
#include <stdint.h>
#include "timers.h"

volatile uint16_t systemTimerTicks = 0;

void initSystemTimer(void) {
    systemTimerTicks = 0;
    T4CONbits.TMR4ON = 0;
    T4CONbits.T4CKPS = 0b10; //1:16 pre-scale
    T4CONbits.T4OUTPS = 14; //1:15 post-scale
    TMR4 = 0;
    PR4 = 50;
    IPR3bits.TMR4IP = 1;
    PIR3bits.TMR4IF = 0;
    PIE3bits.TMR4IE = 1;
    T4CONbits.TMR4ON = 1;
}
