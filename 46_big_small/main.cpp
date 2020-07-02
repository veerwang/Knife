/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年07月02日 
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


void check_big_small() {
	unsigned int i = 1;
	unsigned char* p;
	p = (unsigned char*)&i;
	if ( *p )
		printf("small-t\n");
	else
		printf("big-t\n");
}

int main(int argc, const char *argv[])
{
	std::cout << "big-small test" << std::endl;
	check_big_small();
	return EXIT_SUCCESS;
}
