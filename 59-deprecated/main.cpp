/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月03日 
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

void create() {
	std::cout << "create" << std::endl;
}

[[deprecated("had better not used this function")]]
void display(void) {
	std::cout << "display" << std::endl;
}

int 
main(int argc, const char *argv[]) {
	std::cout << "deprecated test" << std::endl;	
	display();
	create();
	return EXIT_SUCCESS;
}
