/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月03日 
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

#include	"Core.h"
#include	"Object.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "Struct Designed V1.0.0" << std::endl;

	Object<Msgbox> obj;
	obj.DoProcess();
	obj.Display();
	return EXIT_SUCCESS;
}
