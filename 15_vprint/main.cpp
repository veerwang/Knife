/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2017 10:56:53 PM
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

#include <stdarg.h>
#include "head.h"

void Display(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
    	va_end(ap);
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
    	Base<int> base;
	base.Display("%s","hello");
	Display("%s","hello");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
