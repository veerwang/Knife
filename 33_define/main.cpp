/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月08日 
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
#include 	<string.h>

class colordef {
public:
	static const int Black;
	static const int Red;
};

const int colordef::Black = 10;
const int colordef::Red   = 20;

#define COLORDEF(VALUE) { \
	printf("%s:%d\n",std::string(#VALUE).c_str(),colordef::VALUE); \
	printf("---\n"); \
	}while(0);

int 
main(int argc, const char *argv[]) {
	std::cout << "define test" << std::endl;
	COLORDEF(Black)
	COLORDEF(Red)
	return EXIT_SUCCESS;
}
