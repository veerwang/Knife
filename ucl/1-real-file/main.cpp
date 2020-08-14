/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include 	<ucl/ucl.h>
#include	"uclmrg.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "ucl test" << std::endl;

	uclmrg uclm;
	if ( uclm.init() ) {
		std::cout << "uclmrg init sccessful" << std::endl;
	}








	uclm.release();

	return EXIT_SUCCESS;
}
