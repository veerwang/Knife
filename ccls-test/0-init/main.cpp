/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月01日 
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  display_version
 *  Description:  显示本程序版本信息函数 
 * =====================================================================================
 */
void display_version() {
	std::cout << "ccls test" << std::endl;	
}

int 
main(int argc, const char *argv[]) {
	display_version();
	return EXIT_SUCCESS;
}
