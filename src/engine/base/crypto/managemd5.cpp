/*
 * =====================================================================================
 *
 *       Filename:  managemd5.cpp
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

#include 	<openssl/md5.h>

#include 	"managemd5.h"

std::auto_ptr<ManageMD5> ManageMD5::m_Instance;

static unsigned char shash[MD5_DIGEST_LENGTH] = {0};

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
bool ManageMD5::Calculate_MD5(const char* path)
{
	using namespace std;
	bool result = false;
	if 	( access(path,0) == -1 )
	{
		perror("access file");
		return false;
	}
	std::fstream filestream;
	filestream.open(path,ios::binary|ios::in);
	if 	( !filestream )
	{
		perror("can't open the input data file\n");
		return false;
	}
	filestream.seekp(0,ios::end);
	unsigned int length = filestream.tellp();

	if ( length <= 16 )
	{
		printf ( "length less 16 bytes\n" );
		return false;
	}

	unsigned char *buf  = new(std::nothrow) unsigned char[length];

	if ( buf == NULL )
	{
		perror("Can't Allocate Memory for Programe");
		return false;
	}

	filestream.seekp(0,ios::beg);
	filestream.read((char*)buf,length);
	filestream.close();

	MD5_CTX ctx;
	memset(&ctx,0,sizeof(MD5_CTX));
	MD5_Init(&ctx);
	MD5_Update(&ctx,buf,length-16);
	MD5_Final(shash,&ctx);

	for ( int i=0;i<16;i++ )
	{
		if ( buf[length-16+i] != shash[i] )
		{
			result = false;
			goto Exit;
		}
	}

 	result = true;
Exit:
	delete[] buf;
	buf = NULL;
	return result;
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
	return shash;
}
