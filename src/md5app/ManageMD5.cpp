/*
 * =====================================================================================
 *
 *       Filename:  ManageMD5.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月12日 16时44分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstring>
#include        <cstdio>
#include 	<unistd.h>
#include 	<fstream>
#include 	<iostream>

#include 	<openssl/md5.h>

#include 	"ManageMD5.h"

std::auto_ptr<ManageMD5> ManageMD5::m_Instance;

static unsigned char hash[MD5_DIGEST_LENGTH] = {0};

ManageMD5::ManageMD5 ()
{
}

ManageMD5::~ManageMD5 ()
{
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Instance
 *  Description:  Only use this function to init logic class 
 * =====================================================================================
 */
ManageMD5* ManageMD5::Instance()
{
	if 	( m_Instance.get() == 0 )
	{
		m_Instance.reset( new ManageMD5() );
	}
	return m_Instance.get();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Calculate_MD5
 *  Description:  Calculate the MD5 value 
 *         path:  Complete path of file which need to calculate MD5
 * =====================================================================================
 */
void ManageMD5::Calculate_MD5(const char* path)
{
	using namespace std;
	if 	( access(path,0) != 0 )
	{
		printf ( "no find file\n" );
		return;
	}
	std::fstream filestream;
	filestream.open(path,ios::binary|ios::in);
	if 	( !filestream )
	{
		perror("can't open the input data file\n");
		return;
	}
	filestream.seekp(0,ios::end);
	unsigned int length = filestream.tellp();
	unsigned char *buf = new unsigned char[length];

	filestream.seekp(0,ios::beg);
	filestream.read((char*)buf,length);
	filestream.close();

	MD5_CTX ctx;
	memset(&ctx,0,sizeof(MD5_CTX));
	MD5_Init(&ctx);
	MD5_Update(&ctx,buf,length);
	MD5_Final(hash,&ctx);

	delete[] buf;
	buf = NULL;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Get_Hash_Value
 *  Description:  Get the Hash table value 
 *      caution:  Get the Hash value after Calculate_MD5
 * =====================================================================================
 */
unsigned char* ManageMD5::Get_Hash_Value()
{
	return hash;
}
