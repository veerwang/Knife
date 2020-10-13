/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  申请内存是否失败的函数
 *
 *        Version:  1.0
 *        Created:  2020年10月13日 
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
	std::cout << "memory" << std::endl;

	// 注意添加这个std::nothrow
	int *point = new(std::nothrow) int[100];
	if ( point != nullptr ) {
		delete[] point;
		point = nullptr;
	}

	return EXIT_SUCCESS;
}
