/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行nullptr的实验 
 *
 *        Version:  1.0
 *        Created:  2021年10月08日 
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

int 
main(int argc, const char *argv[]) {
	// 初始化为一个空指针
	int* p = nullptr;
	int m = 100;
	p = &m;
	std::cout << *p << std::endl;
	return EXIT_SUCCESS;
}
