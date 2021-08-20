
#include "system.h"
#include "usb_device.h"
#include "usb_device_hid.h"
#include "joystick.h"

void main(void)
{
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    USBDeviceInit();
    USBDeviceAttach();
    while(1)
    {
        #if defined(USB_POLLING)
            USBDeviceTasks();
        #endif
        //Application specific tasks
        JoystickTasks();

    }
}

void __interrupt(__high_priority) SYS_InterruptHigh(void)
{
    #if defined(USB_INTERRUPT)
        USBDeviceTasks();
    #endif
}