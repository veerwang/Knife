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

#include <wangvlib.h> 

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
	WangV::LOG_INIT(NULL);
	WangV::LOG_LEVEL(1<<5);

	WangV::LOG_DESTORY();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
