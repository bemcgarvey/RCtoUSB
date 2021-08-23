#ifndef SYSTEM_H
#define SYSTEM_H

#include <xc.h>
#include <stdbool.h>
#include "usb_config.h"

/*** System States **************************************************/
typedef enum
{
    SYSTEM_STATE_USB_START,
    SYSTEM_STATE_USB_SUSPEND,
    SYSTEM_STATE_USB_RESUME
} SYSTEM_STATE;

void SYSTEM_Initialize( SYSTEM_STATE state );

#define _XTAL_FREQ   48000000L

#endif //SYSTEM_H
