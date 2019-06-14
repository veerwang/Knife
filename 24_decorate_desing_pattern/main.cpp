/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019年06月14日 
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

#include 	"concretecomponent.h"
#include 	"boarddecorator.h"

int main(int argc, const char *argv[])
{
	std::cout << "decorate desinged pattern" << std::endl;
	Component *com = new ConcreteComponent();
	Decorator *bd = new BoardDecorator(com);
	bd->Operation();
	delete com;
	delete bd;
	return EXIT_SUCCESS;
}
