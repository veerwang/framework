/*
 * =====================================================================================
 *
 *       Filename:  managemd5.h
 *
 *    Description:  Deal with md5 function
 *
 *        Version:  1.0
 *        Created:  2012年09月12日 16时39分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  ManageMD5_INC
#define  ManageMD5_INC

#include 	<standard.h>

class ManageMD5
{
	public:
		static ManageMD5* Instance();
		bool Calculate_MD5(const char* path);
		unsigned char* Get_Hash_Value();
	protected:

	private:
		ManageMD5();
		~ManageMD5();
		ManageMD5( const ManageMD5& );
		ManageMD5& operator = (const ManageMD5&);
	private:
		friend class std::auto_ptr<ManageMD5>;
		static std::auto_ptr<ManageMD5>		m_Instance;
};

#endif   /* ----- #ifndef ManageMD5_INC  ----- */
