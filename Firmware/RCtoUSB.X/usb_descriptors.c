
#ifndef __USB_DESCRIPTORS_C
#define __USB_DESCRIPTORS_C

/** INCLUDES *******************************************************/
#include "usb.h"
#include "usb_device_hid.h"

/* Device Descriptor */
const USB_DEVICE_DESCRIPTOR device_dsc = {
    0x12, // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE, // DEVICE descriptor type
    0x0200, // USB Spec Release Number in BCD format
    0x00, // Class Code
    0x00, // Subclass code
    0x00, // Protocol code
    USB_EP0_BUFF_SIZE, // Max packet size for EP0, see usb_config.h
    0x4d63, // Vendor ID
    0x0500, // Product ID
    0x0001, // Device release number in BCD format
    0x01, // Manufacturer string index
    0x02, // Product string index
    0x00, // Device serial number string index
    0x01 // Number of possible configurations
};

/* Configuration 1 Descriptor */
const uint8_t configDescriptor1[] = {
    /* Configuration Descriptor */
    0x09, //sizeof(USB_CFG_DSC),    // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION, // CONFIGURATION descriptor type
    DESC_CONFIG_WORD(0x0022), // Total length of data for this cfg
    1, // Number of interfaces in this cfg
    1, // Index value of this configuration
    0, // Configuration string index
    _DEFAULT | _SELF, // Attributes, see usb_device.h
    100, // Max power consumption (2X mA)

    /* Interface Descriptor */
    0x09, //sizeof(USB_INTF_DSC),   // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    0, // Interface Number
    0, // Alternate Setting Number
    1, // Number of endpoints in this intf
    HID_INTF, // Class code
    0, // Subclass code
    0, // Protocol code
    0, // Interface string index

    /* HID Class-Specific Descriptor */
    0x09, //sizeof(USB_HID_DSC)+3,    // Size of this descriptor in bytes RRoj hack
    DSC_HID, // HID descriptor type
    DESC_CONFIG_WORD(0x0111), // HID Spec Release Number in BCD format (1.11)
    0x00, // Country Code (0x00 for Not supported)
    HID_NUM_OF_DSC, // Number of class descriptors, see usbcfg.h
    DSC_RPT, // Report descriptor type
    DESC_CONFIG_WORD(HID_RPT01_SIZE), //sizeof(hid_rpt01),      // Size of the report descriptor

    /* Endpoint Descriptor */
    0x07, /*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    HID_EP | _EP_IN, //EndpointAddress
    _INTERRUPT, //Attributes
    DESC_CONFIG_WORD(8), //size
    0x01 //Interval
};

/*******************************************************************************
 * HID Report Descriptor - this describes the data format of the reports that
 * are sent between the host and the device.
 *
 * In this example there are only one INPUT report.  This report descriptor can
 * be generated using the HID descriptor tool available at www.usb.org.
 ******************************************************************************/
const struct {
    uint8_t report[HID_RPT01_SIZE];
} hid_rpt01 = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x04,                    // USAGE (Joystick)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x02,                    //   USAGE_PAGE (Simulation Controls)
    0x09, 0xbb,                    //   USAGE (Throttle)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x07,              //   LOGICAL_MAXIMUM (2047)
    0x75, 0x10,                    //   REPORT_SIZE (16)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x05, 0x01,                    //   USAGE_PAGE (Generic Desktop)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x95, 0x02,                    //     REPORT_COUNT (2)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0xc0,                          //   END_COLLECTION
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x09, 0x32,                    //   USAGE (Z)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0xc0                           // END_COLLECTION
};


//Language code string descriptor

const struct {
    uint8_t bLength;
    uint8_t bDscType;
    uint16_t string[1];
}

sd000 = {
    sizeof (sd000), USB_DESCRIPTOR_STRING, {
        0x0409
    }
};

//Manufacturer string descriptor

const struct {
    uint8_t bLength;
    uint8_t bDscType;
    uint16_t string[24];
}

sd001 = {
    sizeof (sd001), USB_DESCRIPTOR_STRING, {
        'Q', 'u', 'a', 'n', 't', 'u', 'm', ' ', 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', ' ',
        'S', 'y', 's', 't', 'e', 'm', 's'
    }
};

//Product string descriptor

const struct {
    uint8_t bLength;
    uint8_t bDscType;
    uint16_t string[7];
}

sd002 = {
    sizeof (sd002), USB_DESCRIPTOR_STRING, {
        'R', 'C', 't', 'o', 'U', 'S', 'B'
    }
};

//Array of configuration descriptors
const uint8_t * const USB_CD_Ptr[] = {
    (const uint8_t * const) &configDescriptor1
};

//Array of string descriptors
const uint8_t * const USB_SD_Ptr[] = {
    (const uint8_t * const) &sd000,
    (const uint8_t * const) &sd001,
    (const uint8_t * const) &sd002
};

/** EOF usb_descriptors.c ***************************************************/

#endif
