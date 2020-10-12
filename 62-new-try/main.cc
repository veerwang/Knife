/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  实验新的申请内存的函数 
 *
 *        Version:  1.0
 *        Created:  2020年10月12日 
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

#include	"newtemplate.hpp"

int 
main(int argc, const char *argv[]) {
	std::cout << "new" << std::endl;	
	int* point = WangV::New(int,100);
	if ( point == nullptr ) return EXIT_FAILURE;
	for (int i=0;i<100;i++) {
		point[i] = i;
		std::cout << point[i] << std::endl;
	}
	delete[] point;
	return EXIT_SUCCESS;
}
