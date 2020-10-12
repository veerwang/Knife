/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行C++异常开发的代码 
 *
 *        Version:  1.0
 *        Created:  2020年10月12日 
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

struct KevinExecption : public std::exception {
	const char * what () const throw () {
		return "KevinException";
	}
};

int 
main(int argc, const char *argv[]) {
	std::cout << "try modify catch V1.0.0" << std::endl;
	try {
		throw KevinExecption();
	}
	catch ( KevinExecption& e ) {
		std::cerr << "Exception Catched: " << e.what() << std::endl;
	}
	std::cout << "finish test" << std::endl;
	return EXIT_SUCCESS;
}
