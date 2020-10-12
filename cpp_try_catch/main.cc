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

int 
main(int argc, const char *argv[]) {
	std::cout << "try catch V1.0.0" << std::endl;
	constexpr uint64_t max_buffer_length = static_cast<int64_t>(1024)*1024*1024*4;

	int *bigpoint = nullptr;
	/*
	try {
		bigpoint = new int[max_buffer_length];
	}catch( std::exception& e ) {
		std::cerr << "exception fail in apply memory" << e.what() << std::endl;
	}
	*/
		bigpoint = new int[max_buffer_length];
	
	delete[] bigpoint;
	std::cout << "finish test" << std::endl;
	return EXIT_SUCCESS;
}
