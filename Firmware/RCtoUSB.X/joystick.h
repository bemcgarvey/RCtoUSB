
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdbool.h>
#include <stddef.h>
#include "usb_device.h"
#include "usb_device_hid.h"

extern uint16_t packetCount;

void JoystickInitialize(void);
//void JoystickStart(void);
void JoystickTasks(void);
bool JoystickEventHandler(unsigned int event, void *pdata, size_t size);
void JoystickSOFHandler(void);

#endif
