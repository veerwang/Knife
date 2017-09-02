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
	while ( key != KEY_ESC )
	{
		usleep(1000);

		key = WangV::GetPCKey();
	}

	ThreadHost<>*  pbasethread; 
	pbasethread = new ThreadHost<>();
	pbasethread->Set_Interval_Second(2);
	pbasethread->Start();
	if ( pbasethread != NULL )	
	{
		pbasethread->Stop();
		delete pbasethread;
	}

	WangV::RestoreKey();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
