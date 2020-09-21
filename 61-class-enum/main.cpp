/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月21日 
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

enum class WEEK : uint32_t {
	MONDAY  = 1,
	FRIDAY  = 2,
	SUNDAY  = 7,
};

int
main(int argc, const char *argv[]) {
	std::cout << "class enum test" << std::endl;
	printf("%d\n",static_cast<int>(WEEK::FRIDAY));
	return EXIT_SUCCESS;
}
