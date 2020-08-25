/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月25日 
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

#include	<cstring>

#include	"fileopt.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "file opt pro V1.0.0" << std::endl;	

	std::string text;
	ZFile zf;
	zf.ReadAllText("Makefile",text);
	std::cout << text << std::endl;

	return EXIT_SUCCESS;
}
