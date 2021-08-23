/* 
 * File:   leds.h
 * Author: bemcg
 *
 * Created on August 23, 2021, 12:18 PM
 */

#ifndef LEDS_H
#define	LEDS_H

#define led1On()        (LATCbits.LATC1 = 1)
#define led1Off()       (LATCbits.LATC1 = 0)
#define led1Toggle()    (LATCbits.LATC1 ^= 1)
#define led2On()        (LATCbits.LATC2 = 1)
#define led2Off()       (LATCbits.LATC2 = 0)
#define led2Toggle()    (LATCbits.LATC2 ^= 1)

#endif	/* LEDS_H */

