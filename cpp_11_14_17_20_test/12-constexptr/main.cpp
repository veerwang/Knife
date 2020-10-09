/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年10月09日 
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
	std::cout << "const ptr test" << std::endl;	

	// 常量表达式
	constexpr int MAX = 10;

	// 常量
	const int HM = 10;

	int b[HM]  = {1,2,3,4,5,6,7,8,9,0};
	int a[MAX] = {1,2,3,4,5,6,7,8,9,0};
	for (auto e : a ) {
		std::cout << e << std::endl;
	}
	for (auto e : b ) {
		std::cout << e << std::endl;
	}

	return EXIT_SUCCESS;
}
