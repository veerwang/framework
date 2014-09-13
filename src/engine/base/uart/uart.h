/*
 * =====================================================================================
 *
 *       Filename:  Uart.h
 *
 *    Description:  Manage the UART port class
 *
 *        Version:  1.0
 *        Created:  2012年11月07日 13时42分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  _UART_INC
#define  _UART_INC

#include 	"cssl.h"
class Uart
{
	public:
		Uart ();                             /* constructor */
		~Uart ();                            /* destructor */
		bool Init_Uart();
		void Destory_Uart();
		void Send_Data(uint8_t *data,int length);
		void Get_Data(uint8_t *data,int length);

	protected:

	private:
		cssl_t 				*m_Serial;
};

#endif   /* ----- #ifndef _UART_INC  ----- */
