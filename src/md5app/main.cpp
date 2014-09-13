/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月13日 10时04分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<cstring>
#include 	<unistd.h>
#include 	<fstream>
#include 	<iostream>

#include 	"ManageMD5.h"	

int main( int argc,char* argv[] )
{
	using namespace std;
	ManageMD5 *md5 = ManageMD5::Instance();

	if 	( argc != 2 )
	{
		printf ( "parameters count error\n" );
		return EXIT_FAILURE;
	}

	md5->Calculate_MD5(argv[1]);
	unsigned char *hash = md5->Get_Hash_Value();

	std::fstream filestream;
	filestream.open(argv[1],ios::out|ios::app|ios::binary);
	if 	( !filestream )
	{
		perror("can't open the input data file\n");
		return EXIT_FAILURE;
	}

	filestream.seekp(0,ios::end);
	filestream.write((char *)hash,16);
	filestream.flush();
	filestream.close();

	return EXIT_SUCCESS;
}
