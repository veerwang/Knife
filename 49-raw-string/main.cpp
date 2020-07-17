/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年07月17日 
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
#include 	<string>

int main(int argc, const char *argv[]) {
	std::cout << "raw string test" << std::endl;	
	std::string title = "hello the world\n";
	std::cout << title;

	std::string rawtitle = R"(hello the world\n)";
	std::cout << rawtitle;

	return EXIT_SUCCESS;
}
