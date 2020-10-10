/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行模板测试的代码
 *
 *        Version:  1.0
 *        Created:  2020年10月10日 
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

#include 	"templatehead.hpp"

int 
main(int argc, const char *argv[]) {
	std::cout << "template test" << std::endl;	
	WangV::Utils<int> obj;

	return EXIT_SUCCESS;
}
