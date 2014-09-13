/*
 * =====================================================================================
 *
 *       Filename:  USB.cpp
 *
 *    Description:  Implementation of USB
 *
 *        Version:  1.0
 *        Created:  2012年11月03日 12时27分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdio>
#include 	"usb.h"

#define    USB_VENDOR_ID  		0x05ba
#define    USB_PRODUCT_ID		0x000a 

USB::USB ()
{
}

USB::~USB ()
{
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_USB
 *  Description:  Init the USB libary used environment
 * =====================================================================================
 */
bool USB::Init_USB()
{
	int rc = 1;
	rc = libusb_init(NULL);
	if 	( rc < 0 )
	{
		perror("fail to init usb lib");
		return false;
	}
//	m_devh = NULL;
//	m_devh = libusb_open_device_with_vid_pid(NULL, 0x05ba, 0x000a);
//	if 	( m_devh == NULL )
//	{
//		perror("fail to open the usb device");
//		libusb_exit(NULL);
//		return false;
//	}
//	rc = libusb_claim_interface(m_devh, 0);
//	if 	(rc < 0) 
//	{
//		perror("fail to claim interface");
//		libusb_close(m_devh);
//		libusb_exit(NULL);
//		return false;
//	}

	return true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destroy_USB
 *  Description:  Destroy the USB library environment
 * =====================================================================================
 */
void USB::Destroy_USB()
{
//	libusb_release_interface(m_devh, 0);
//	libusb_close(m_devh);
	libusb_exit(NULL);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Show_USB_List
 *  Description:  List All USB device of system
 * =====================================================================================
 */
void USB::Show_USB_List()
{
	libusb_device **devs;
	ssize_t cnt;
	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0)
	{
		perror("can't get device list");
		return;
	}

	libusb_device *dev;
	int i = 0;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) 
		{
			fprintf(stderr, "failed to get device descriptor");
			return;
		}

		printf("%04x:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
	}

	libusb_free_device_list(devs, 1);
}
