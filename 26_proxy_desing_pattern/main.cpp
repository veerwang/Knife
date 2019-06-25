/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019年06月25日 
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

#include 	"concretesubject.h"
#include 	"proxy.h"

int main(int argc, const char *argv[])
{
	std::cout << "proxy design pattern" << std::endl;
	Subject *core = (Subject *)new ConcreteSubject();

	Proxy proxy;
	proxy.InitCore(core);
	proxy.Request();
	delete core;
	core = NULL;
	return EXIT_SUCCESS;
}
