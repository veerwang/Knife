/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年03月26日 
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

void init_module()  {
	std::cout << "init modules" << std::endl;
}

int main(int argc, const char *argv[]) {
	std::cout << "Program Version: V1.0.0" << std::endl;		
	init_module();
	return EXIT_SUCCESS;
}
