/*
 * =====================================================================================
 *
 *       Filename:  Uart.cpp
 *
 *    Description:  implementation of Uart class
 *
 *        Version:  1.0
 *        Created:  2012年11月07日 13时43分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<list>
#include 	<cstdlib>
#include 	<cstdio>

#include 	"uart.h"

std::list<uint8_t>		m_Buf;

static void callback(int id,
	             uint8_t *buf,
		     int length)
{
	for ( int i=0;i<length;i++ )
	{
		m_Buf.push_back(buf[i]);
	}
}

Uart::Uart ()
{
}

Uart::~Uart ()
{
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_Uart
 *  Description:  Init the Uart class 
 * =====================================================================================
 */
bool Uart::Init_Uart()
{
	cssl_start();
	m_Serial = cssl_open("/dev/ttySAC0",callback,0,19200,8,0,1);
	if ( !m_Serial )
	{
		printf("%s\n",cssl_geterrormsg());
		cssl_stop();
		return false;
	}
	else
		printf ( "OK\n" );
	m_Buf.clear();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Destroy_Uart
 *  Description:  Destroy the Uart class 
 * =====================================================================================
 */
void Uart::Destory_Uart()
{
	cssl_close(m_Serial);
	cssl_stop();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Send_Data
 *  Description:  Send the Data into 
 * =====================================================================================
 */
void Uart::Send_Data(uint8_t *data,int length)
{
	cssl_putdata(m_Serial,data,length);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Data
 *  Description:  Get the Data from module 
 * =====================================================================================
 */
void Uart::Get_Data(uint8_t *data,int length)
{
	for ( int i=0;i<length;i++ )
	{
		data[i] = m_Buf.front();
		m_Buf.pop_front();
	}
}
