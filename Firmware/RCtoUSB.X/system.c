#include <xc.h>
#include "system.h"
#include "usb_device.h"
#include "timers.h"
#include "satellite.h"
 
void initPins(void);
void configInterrupts(void);

void SYSTEM_Initialize( SYSTEM_STATE state )
{
    initPins();
    configInterrupts();
    initSystemTimer();
    switch(state)
    {
        case SYSTEM_STATE_USB_START:
             //In this devices family of USB microcontrollers, the PLL will not power up and be enabled
             //by default, even if a PLL enabled oscillator configuration is selected (such as HS+PLL).
             //This allows the device to power up at a lower initial operating frequency, which can be
             //advantageous when powered from a source which is not gauranteed to be adequate for 48MHz
             //operation.  On these devices, user firmware needs to manually set the OSCTUNE<PLLEN> bit to
             //power up the PLL.
             {
                 unsigned int pll_startup_counter = 600;
                 OSCTUNEbits.PLLEN = 1;  //Enable the PLL and wait 2+ms until the PLL locks before enabling USB module
                 while(pll_startup_counter--);
             }
             //Device switches over automatically to PLL output after PLL is locked and ready.
            break;
        case SYSTEM_STATE_USB_SUSPEND: 
            break;
            
        case SYSTEM_STATE_USB_RESUME:
            OSCCON = 0x70;		//Primary clock source selected.
            
            //Adding a software start up delay will ensure
            //that the primary oscillator and PLL are running before executing any other
            //code.  If the PLL isn't being used, (ex: primary osc = 48MHz externally applied EC)
            //then this code adds a small unnecessary delay, but it is harmless to execute anyway.
            {
                unsigned int pll_startup_counter = 800;	//Long delay at 31kHz, but ~0.8ms at 48MHz
                while(pll_startup_counter--);			//Clock will switch over while executing this delay loop
            }
            break;
    }
}

void initPins(void) {
    LATA = 0;
    LATB = 0;
    LATC = 0;
    TRISA = 0;
    TRISB = 0b00000001;
    TRISC = 0b10000000;
    ANCON0 = 0b00011111;
    ANCON1 = 0b00011111;
    INTCON2bits.RBPU = 0;
    //Lock PPS
    EECON2 = 0x55;
    EECON2 = 0xAA;
    PPSCONbits.IOLOCK = 1;
}

void configInterrupts(void) {
    INTCONbits.INT0IF = 0;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0IE = 1;
    RCONbits.IPEN = 1;
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
}