/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
 *******************************************************************************/

/** INCLUDES *******************************************************/
#include "system.h"
#include <stdint.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_hid.h"
#include "joystick.h"
#include "usb_config.h"

/*******************************************************************************
 * Report Data Types - These typedefs will mirror the reports defined in the
 * HID report descriptor so that the application has an easy way to see what
 * the report will look like as well as access/modify each of the members of the
 * report.
 ******************************************************************************/

#define HAT_SWITCH_NORTH            0x0
#define HAT_SWITCH_NORTH_EAST       0x1
#define HAT_SWITCH_EAST             0x2
#define HAT_SWITCH_SOUTH_EAST       0x3
#define HAT_SWITCH_SOUTH            0x4
#define HAT_SWITCH_SOUTH_WEST       0x5
#define HAT_SWITCH_WEST             0x6
#define HAT_SWITCH_NORTH_WEST       0x7
#define HAT_SWITCH_NULL             0x8

/** TYPE DEFINITIONS ************************************************/
typedef union _INTPUT_CONTROLS_TYPEDEF
{
    struct
    {
        struct
        {
            uint8_t square:1;
            uint8_t x:1;
            uint8_t o:1;
            uint8_t triangle:1;
            uint8_t L1:1;
            uint8_t R1:1;
            uint8_t L2:1;
            uint8_t R2:1;//
            uint8_t select:1;
            uint8_t start:1;
            uint8_t left_stick:1;
            uint8_t right_stick:1;
            uint8_t home:1;
            uint8_t :3;    //filler
        } buttons;
        struct
        {
            uint8_t hat_switch:4;
            uint8_t :4;//filler
        } hat_switch;
        struct
        {
            uint8_t X;
            uint8_t Y;
            uint8_t Z;
            uint8_t Rz;
        } analog_stick;
    } members;
    uint8_t val[7];
} INPUT_CONTROLS;

volatile INPUT_CONTROLS joystick_input;

volatile USB_HANDLE txHandle;  //Handle for txPacket


void JoystickInitialize(void) {
    TRISBbits.TRISB0 = 1;  //Set button as input
    INTCON2bits.RBPU = 0;
    LATC = 0;
    TRISC = 0;
    LATCbits.LATC1 = 1;
    LATCbits.LATC2 = 1;
    
    ANCON0 = 0xff;  //All digital inputs 
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
        if(PORTBbits.RB0 == 0)
        {
            //Indicate that the "x" button is pressed, but none others
            joystick_input.members.buttons.x = 1;
            joystick_input.members.buttons.square = 0;
            joystick_input.members.buttons.o = 0;
            joystick_input.members.buttons.triangle = 0;
            joystick_input.members.buttons.L1 = 0;
            joystick_input.members.buttons.R1 = 0;
            joystick_input.members.buttons.L2 = 0;
            joystick_input.members.buttons.R2 = 0;
            joystick_input.members.buttons.select = 0;
            joystick_input.members.buttons.start = 0;
            joystick_input.members.buttons.left_stick = 0;
            joystick_input.members.buttons.right_stick = 0;
            joystick_input.members.buttons.home = 0;

            //Move the hat switch to the "east" position
            joystick_input.members.hat_switch.hat_switch = HAT_SWITCH_EAST;

            //Move the X and Y coordinates to the their extreme values (0x80 is
            //  in the middle - no value).
            joystick_input.members.analog_stick.X = 0;
            joystick_input.members.analog_stick.Y = 0;

            //Send the packet over USB to the host.
            txHandle = HIDTxPacket(HID_EP, (uint8_t*)&joystick_input, sizeof(joystick_input));

        }
        else
        {
            //Reset values of the controller to default state

            //Buttons
            joystick_input.val[0] = 0x00;
            joystick_input.val[1] = 0x00;

            //Hat switch
            joystick_input.val[2] = 0x08;

            //Analog sticks
            joystick_input.val[3] = 0x80;
            joystick_input.val[4] = 0x80;
            joystick_input.val[5] = 0x80;
            joystick_input.val[6] = 0x80;

            //Send the 7 byte packet over USB to the host.
            txHandle = HIDTxPacket(HID_EP, (uint8_t*)&joystick_input, sizeof(joystick_input));
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
