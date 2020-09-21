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

/* C++11 比较安全的形式，可防止不同的类型之间直接进行比较 */
enum class WEEK : uint32_t {
	MONDAY  = 1,
	FRIDAY  = 2,
	SUNDAY  = 7,
	ENDDAY  = 0xfffff,
};

enum class HUMAN : bool {
	MAN	= true,
	WOMAN	= false,
};

int
main(int argc, const char *argv[]) {
	std::cout << "class enum test" << std::endl;
	printf("%d\n",static_cast<int>(WEEK::FRIDAY));
	printf("%x\n",static_cast<int>(WEEK::ENDDAY));
	if ( HUMAN::MAN == (HUMAN)WEEK::MONDAY )
		std::cout << "GOOD" << std::endl;
	return EXIT_SUCCESS;
}
