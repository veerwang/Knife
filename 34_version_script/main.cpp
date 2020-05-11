/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月11日 
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

extern "C" void display_version();
void do_action();
void display_version_2();
extern "C" void drawme();

int main(int argc, const char *argv[])
{
	std::cout << "Programe Test V1.0.0" << std::endl;	
	display_version();
	do_action();
	display_version_2();
	drawme();
	return EXIT_SUCCESS;
}
