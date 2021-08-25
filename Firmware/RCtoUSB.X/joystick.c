
/** INCLUDES *******************************************************/
#include "system.h"
#include <stdint.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_hid.h"
#include "joystick.h"
#include "usb_config.h"
#include "satellite.h"

/** TYPE DEFINITIONS ************************************************/
typedef struct _INTPUT_CONTROLS_TYPEDEF {
    uint16_t aileron;
    uint16_t elevator;
    uint16_t throttle;
    uint16_t rudder;
    uint16_t flaps;
    uint16_t slider;
    uint16_t wheel;
    uint8_t gear : 1;
    uint8_t button1 : 1;
    uint8_t button2 : 1;
    uint8_t button3 : 1;
    uint8_t button4 : 1;
    uint8_t:3;
} INPUT_CONTROLS;

volatile INPUT_CONTROLS joystick_input;
volatile USB_HANDLE txHandle; //Handle for txPacket

void JoystickInitialize(void) {
    /* initialize the handles to invalid so we know they aren't being used. */
    txHandle = NULL;
    //enable the HID endpoint
    USBEnableEndpoint(HID_EP, USB_IN_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
}//end UserInit

void JoystickTasks(void) {
    if (USBGetDeviceState() < CONFIGURED_STATE) {
        return;
    }
    if (USBIsDeviceSuspended() == true) {
        return;
    }
    
    if (packetComplete) {
        packetComplete = false;
        //set joystick_input fields from rxBuffer[activeBuffer ^ 1]
    }
    
    //USB is connected and active so create a report
    if (HIDTxHandleBusy(txHandle) == false) {
        if (PORTBbits.RB0 == 0) {
            joystick_input.aileron = 0;
            joystick_input.elevator = 2047;
            joystick_input.throttle = 512;
            joystick_input.rudder = 1500;
            joystick_input.flaps = 1024;
            joystick_input.slider = 450;
            joystick_input.wheel = 1600;
            joystick_input.gear = 1;
            joystick_input.button1 = 0;
            joystick_input.button2 = 1;
            joystick_input.button3 = 0;
            joystick_input.button4 = 1;
            //Send the packet over USB to the host.
            txHandle = HIDTxPacket(HID_EP, (uint8_t*) & joystick_input, sizeof (joystick_input));
        } else {
            joystick_input.aileron = 1024;
            joystick_input.elevator = 1024;
            joystick_input.throttle = 0;
            joystick_input.rudder = 1024;
            joystick_input.flaps = 0;
            joystick_input.slider = 0;
            joystick_input.wheel = 0;
            joystick_input.gear = 0;
            joystick_input.button1 = 0;
            joystick_input.button2 = 0;
            joystick_input.button3 = 0;
            joystick_input.button4 = 0;
            txHandle = HIDTxPacket(HID_EP, (uint8_t*) & joystick_input, sizeof (joystick_input));
        }
    }
}

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
