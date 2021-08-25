/* 
 * File:   satellite.h
 * Author: bemcg
 *
 * Created on August 23, 2021, 11:45 AM
 */

#ifndef SATELLITE_H
#define	SATELLITE_H

#define satPowerOn()    (LATCbits.LATC0 = 1)
#define satPowerOff()   (LATCbits.LATC0 = 0)

enum {
    DSMX_INTERNAL_11MS = 9, DSMX_EXTERNAL_11MS = 10, DSMX_INTERNAL_22MS = 7
    , DSMX_EXTERNAL_22MS = 8, DSM2_INTERNAL_22MS = 3, DSM2_EXTERNAL_22MS = 4
    , DSM2_INTERNAL_11MS = 5, DSM2_EXTERNAL_11MS = 6
};

typedef union {
    struct {
        uint8_t system;
        uint8_t fades;
        uint16_t channels[7];
    };
    uint8_t bytes[16];
} DataPacket;

extern volatile bool packetComplete;
extern volatile uint8_t activeBuffer;
extern volatile uint8_t rxTimerTicks;
extern volatile DataPacket rxBuffer[2];

void initSat(void);
void bindSat(int8_t pulses);
bool satPowered(void);
void handleRxInterrupt(void);

#endif	/* SATELLITE_H */

