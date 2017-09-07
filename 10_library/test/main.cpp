/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2017 09:25:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com
 *        Company:  Landicorp
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>

#include <threadtemplate.h> 
#include <wangvlib.h> 
#include <keymap.h>

template<typename T>
class MyPolicy
{
	public:
		void Run()
		{
			WangV::log_module_write((WangV::LOG_INFO),__FILE__,__FUNCTION__,__LINE__,"pthread %s","kevin");
		}
};
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<WangV::get_version()<<std::endl;
	WangV::log_module_write((WangV::LOG_INFO),__FILE__,__FUNCTION__,__LINE__,"info %s","kevin");
	WangV::InitKey();
	char key = 0;

	ThreadHost<MyPolicy>*  pbasethread; 
	pbasethread = new ThreadHost<MyPolicy>();
	pbasethread->Set_Interval_Second(1);
	pbasethread->Start();

	WangV::encrypt_file("test.dat","1.enc");
	WangV::decrypt_file("1.enc","1.dec");

	while ( key != KEY_ESC )
	{
		usleep(1000);

		key = WangV::GetPCKey();
	}

	if ( pbasethread != NULL )	
	{
		pbasethread->Stop();
		delete pbasethread;
	}

	WangV::RestoreKey();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
