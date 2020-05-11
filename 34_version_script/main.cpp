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

void display_version();
void do_action();

int main(int argc, const char *argv[])
{
	std::cout << "Programe Test V1.0.0" << std::endl;	
	display_version();
	do_action();
	return EXIT_SUCCESS;
}
