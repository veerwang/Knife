/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月12日 
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
#include	<loki/Functor.h>

int
add(int x,int y) {
	return x + y;
}

int
multi(int x,int y) {
	return x * y;
}

int main(int argc, const char *argv[])
{
	std::cout << "functor test" << std::endl;
	typedef Loki::Functor<int,LOKI_TYPELIST_2(int,int)> CREATEFUN;
	CREATEFUN func = add; 
	std::cout << func(10,10) << std::endl;

	func = multi; 
	std::cout << func(10,10) << std::endl;

	return EXIT_SUCCESS;
}
