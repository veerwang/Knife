/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月04日 
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

void get_tp(int x[5], int y[5]) {
	for ( int i=0;i<5;i++ ) {
		x[i] = 0x10;
		y[i] = 0x20;
	}
}

int 
main(int argc, const char *argv[]) {
	std::cout << "Test V1.0.0" << std::endl;	
	int x[5] = {0},y[5] = {0};
	get_tp(x,y);
	for ( int i=0;i<5;i++ ) {
		std::cout << x[i] << std::endl;
		std::cout << y[i] << std::endl;
	}

	return EXIT_SUCCESS;
}
