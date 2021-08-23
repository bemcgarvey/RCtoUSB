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

enum {DSMX_INTERNAL_11MS = 9, DSMX_EXTERNAL_11MS = 10, DSMX_INTERNAL_22MS = 7
        , DSMX_EXTERNAL_22MS = 8, DSM2_INTERNAL_22MS = 3, DSM2_EXTERNAL_22MS = 4
        , DSM2_INTERNAL_11MS = 5, DSM2_EXTERNAL_11MS = 6};

void initSat(void);
void bindSat(int8_t pulses);

#endif	/* SATELLITE_H */

