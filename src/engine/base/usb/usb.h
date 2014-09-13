/*
 * =====================================================================================
 *
 *       Filename:  USB.h
 *
 *    Description:  Management of USB port
 *
 *        Version:  1.0
 *        Created:  2012年11月03日 12时24分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  _USB_INC
#define  _USB_INC

#include 	<libusb.h>

class USB
{
	public:
		USB ();                             /* constructor */
		~USB ();                            /* destructor */
		bool Init_USB();
		void Destroy_USB();


		void Show_USB_List();
	protected:

	private:
		struct libusb_device_handle 			*m_devh;

};

#endif   /* ----- #ifndef _USB_INC  ----- */
