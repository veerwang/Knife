/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  实验C++17标准，在if与switch中声明变量
 *
 *        Version:  1.0
 *        Created:  2021年11月30日 
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

int getValue() {
	return 10;
}

int 
main(int argc, const char *argv[]) {
		
	// 关键语句，value只在if语句中起作用
	if ( int value = getValue() ) {
		std::cout << value << std::endl;
	}
	//std::cout << value << std::endl;

	// 关键语句，s只在switch语句中起作用
	switch ( int s = getValue() ) {
		case 2:/* variable case */
			std::cout << "2" << std::endl;	
			break;
		case 10:/* variable case */
			std::cout << "10 new" << s << std::endl;	
			break;
		default:
			std::cout << "hello" << std::endl;
	}
	
	return EXIT_SUCCESS;
}
