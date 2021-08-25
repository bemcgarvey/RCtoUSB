
#include "system.h"
#include <stdint.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_hid.h"
#include "joystick.h"
#include "usb_config.h"
#include "satellite.h"

uint16_t packetCount = 0;

typedef struct {
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
    uint8_t empty : 3;
} INPUT_CONTROLS;

volatile INPUT_CONTROLS joystick_input = {1024, 1024, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0};
volatile USB_HANDLE txHandle;

void JoystickInitialize(void) {
    txHandle = NULL;
    USBEnableEndpoint(HID_EP, USB_IN_ENABLED | USB_HANDSHAKE_ENABLED | USB_DISALLOW_SETUP);
}

void JoystickTasks(void) {
    if (USBGetDeviceState() < CONFIGURED_STATE) {
        return;
    }
    if (USBIsDeviceSuspended() == true) {
        return;
    }
    //TODO Is it ok to write to buffer even if usb is currently transmitting it?
    //Or should we copy data to a new buffer and then give it to usb.
    if (packetComplete) {
        packetComplete = false;
        ++packetCount;
        //TODO set joystick_input fields from rxBuffer[activeBuffer ^ 1]
        uint8_t completeBuffer = activeBuffer ^ 1;
        for (char i = 0; i < 7; ++i) {
            uint8_t channel = rxBuffer[completeBuffer].channels[i] >> 11;
            channel &= 0x0f;
            if (channel == 0) {
                joystick_input.throttle = rxBuffer[completeBuffer].channels[i] & 0x7ff;
            }
        }
    }
    if (HIDTxHandleBusy(txHandle) == false) {
        txHandle = HIDTxPacket(HID_EP, (uint8_t*) & joystick_input, sizeof (joystick_input));
    }
}

void JoystickIdleRateCallback(uint8_t reportId, uint8_t idleRate) {
    //Make sure the host is requesting to set the idleRate on a legal/implemented
    //report ID.  In applications that don't implement report IDs (such as this
    //firmware) the value should be == 0.
}

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
