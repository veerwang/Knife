/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019年06月05日 
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

#include 	"abstraction.h"
#include 	"implementation.h"

int main(int argc, const char *argv[])
{
	std::cout << "Designed Pattern template mode" << std::endl;

	Abstraction *imp = new Implementation ();
	imp->TemplateMethod();
	imp->Process();
	delete imp;
	
	return EXIT_SUCCESS;
}
