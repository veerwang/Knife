/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  验证后验型while类型 
 *
 *        Version:  1.0
 *        Created:  2020年10月26日 
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

int 
main(int argc, const char *argv[]) {
	int recode = 1;	
	do{
		std::cout << "hello --> " << recode << std::endl;
		recode --;
	} while( recode != 0 );

	return EXIT_SUCCESS;
}
