/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  类的描述
 *
 *        Version:  1.0
 *        Created:  2021年09月06日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

// 该变量在外部模块,被声明为100
extern const int cversion;

int 
main(int argc, const char *argv[]) {
	std::cout << cversion  << std::endl;	
	return EXIT_SUCCESS;
}
