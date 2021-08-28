#include <xc.h>
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
    uint16_t throttle;
    uint16_t x;
    uint16_t y;
    uint16_t z;
} INPUT_CONTROLS;

#define CHANNEL_HIGH_VALUE  1536
#define CHANNEL_LOW_VALUE   512

volatile INPUT_CONTROLS joystick_input = {0, 1024, 1024, 1024};
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
    if (HIDTxHandleBusy(txHandle) == false) {
        if (packetComplete) {
            packetComplete = false;
            ++packetCount;
            uint16_t *channelData = (uint16_t *)rxBuffer[activeBuffer ^ 1].channels;
            for (char i = 0; i < 7; ++i) {
                uint8_t channel = *channelData >> 11;
                channel &= 0x0f;
                uint16_t value = *channelData & 0x7ff;
                switch (channel) {
                    case 0:
                        joystick_input.throttle = value;
                        break;
                    case 1:
                        joystick_input.x = value;
                        break;
                    case 2:
                        joystick_input.y = value;
                        break;
                    case 3:
                        joystick_input.z = value;
                        break;
                }
                ++channelData;
            }
        }
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
