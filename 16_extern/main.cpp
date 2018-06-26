#if !defined(INCLUDED_MAIN_CPP)
#define INCLUDED_MAIN_CPP  1

/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年06月20日 17时15分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "head.h"

extern "C"  {
	extern int g_name;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	printf ( "%d\n",g_version );
	add_fun();
	foo();
	printf ( "%d\n",g_version );
	printf ( "g_name = %d\n",g_name );
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

#endif /* !defined(INCLUDED_MAIN_CPP) */
