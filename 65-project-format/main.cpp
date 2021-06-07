/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  测试使用
 *
 *        Version:  1.0
 *        Created:  2021年06月07日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

void print_hello() {
	std::cout << "hello the word" << std::endl;
}

int 
main(int argc, const char *argv[]) {
	std::cout << "hello" << std::endl;	
	print_hello();
	return EXIT_SUCCESS;
}
