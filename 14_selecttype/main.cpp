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

#include "head.h"

class BaseClass
{
public:
	BaseClass() : m_ID(12) {;}
	~BaseClass() {;}

	int m_ID ;
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
	std::cout<<"hello the world"<<std::endl;

	DefineType<BaseClass,true> bp;
	printf ( "%d\n",bp.m_bp.m_ID );

	DefineType<BaseClass,false> bpp;
	printf ( "%d\n",(bpp.m_bp)->m_ID );

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
