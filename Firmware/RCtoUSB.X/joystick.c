
/** INCLUDES *******************************************************/
#include "system.h"
#include <stdint.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_hid.h"
#include "joystick.h"
#include "usb_config.h"

/** TYPE DEFINITIONS ************************************************/
typedef struct _INTPUT_CONTROLS_TYPEDEF {
    uint16_t x;
    uint16_t y;
    uint16_t throttle;
    uint16_t z;
    uint16_t rx;
    uint16_t ry;
    uint16_t rz;
    uint16_t slider;
    uint16_t wheel;
    uint16_t dial;
    uint8_t button1 : 1;
    uint8_t button2 : 1;
uint8_t:
    6;
} INPUT_CONTROLS;

volatile INPUT_CONTROLS joystick_input;

volatile USB_HANDLE txHandle; //Handle for txPacket

void JoystickInitialize(void) {
    TRISBbits.TRISB0 = 1; //Set button as input
    INTCON2bits.RBPU = 0;
    LATC = 0;
    TRISC = 0;
    LATCbits.LATC1 = 1;
    LATCbits.LATC2 = 1;

    ANCON0 = 0xff; //All digital inputs 
    ANCON1 = 0xff;
    /* initialize the handles to invalid so we know they aren't being used. */
    txHandle = NULL;
    //enable the HID endpoint
    USBEnableEndpoint(HID_EP, USB_IN_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
}//end UserInit

void JoystickTasks(void) {

    /* If the USB device isn't configured yet, we can't really do anything
     * else since we don't have a host to talk to.  So jump back to the
     * top of the while loop. */
    if (USBGetDeviceState() < CONFIGURED_STATE) {
        return;
    }

    /* If we are currently suspended, then we need to see if we need to
     * issue a remote wakeup.  In either case, we shouldn't process any
     * keyboard commands since we aren't currently communicating to the host
     * thus just continue back to the start of the while loop. */
    if (USBIsDeviceSuspended() == true) {
        return;
    }

    //USB is connected and active so create a report
    if (HIDTxHandleBusy(txHandle) == false) {
        if (PORTBbits.RB0 == 0) {
            joystick_input.x = 0;
            joystick_input.y = 2047;
            joystick_input.throttle = 512;
            joystick_input.rx = 0;
            joystick_input.ry = 0;
            joystick_input.rz = 0;
            joystick_input.slider = 2000;
            joystick_input.wheel = 0;
            joystick_input.dial = 0;
            joystick_input.button1 = 1;
            joystick_input.button2 = 0;
            //Send the packet over USB to the host.
            txHandle = HIDTxPacket(HID_EP, (uint8_t*) & joystick_input, sizeof (joystick_input));

        } else {
            joystick_input.x = 1024;
            joystick_input.y = 1024;
            joystick_input.throttle = 0;
            joystick_input.rx = 0;
            joystick_input.ry = 0;
            joystick_input.rz = 0;
            joystick_input.slider = 0;
            joystick_input.wheel = 0;
            joystick_input.dial = 0;
            joystick_input.button1 = 0;
            joystick_input.button2 = 0;
            txHandle = HIDTxPacket(HID_EP, (uint8_t*) & joystick_input, sizeof (joystick_input));
        }
    }
}//end ProcessIO

void JoystickIdleRateCallback(uint8_t reportId, uint8_t idleRate) {
    //Make sure the host is requesting to set the idleRate on a legal/implemented
    //report ID.  In applications that don't implement report IDs (such as this
    //firmware) the value should be == 0.
}

/*******************************************************************************
 * Function: void APP_DeviceMouseSOFHandler(void)
 *
 * Overview: Handles SOF events.  This is used to calculate the mouse movement
 *           based on the SOF counter instead of a device timer or CPU clocks.
 *           It can also be used to handle idle rate issues, if applicable for
 *           the demo.
 *
 * Input: none
 * Output: none
 *
 ******************************************************************************/
void JoystickSOFHandler(void) {
    /* We will be getting SOF packets before we get the SET_CONFIGURATION
     * packet that will configure this device, thus, we need to make sure that
     * we are actually initialized and open before we do anything else,
     * otherwise we should exit the function without doing anything.
     */
    if (USBGetDeviceState() != CONFIGURED_STATE) {
        return;
    }
}
