/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月04日 
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

#include	<vector>

#include	"fileopt.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "File Opt" << std::endl;	

	ZFile zf("README.md",'r');
	ZFile::this_string p = zf.GetPath();
	std::cout << p << std::endl;
	std::cout << zf.GetFileLength() << std::endl;

	std::vector<char> context;
	zf.ReadAll(context);
	for (auto a : context) {
		std::cout << a;
	}
	std::cout << "" << std::endl;

	return EXIT_SUCCESS;
}
