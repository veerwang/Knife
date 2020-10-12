/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行C++异常开发的代码 
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

int 
main(int argc, const char *argv[]) {
	std::cout << "try catch V1.0.0" << std::endl;

	// 采用这类方法，就可以保证不被core dump
	try {
		throw "There is a exception";
	}catch( const char* msg ) {
		std::cerr  << msg << std::endl; 
	}

	std::cout << "finish code" << std::endl;

	return EXIT_SUCCESS;
}
