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
	// 采用这类方法，就可以保证不被core dump
	try {
		bigpoint = new int[max_buffer_length];
	}catch( std::bad_alloc& e ) {
		std::cerr  << "new memory fail" << std::endl;
		// 进行重新分配内存
	}catch( std::exception& e ) {
		std::cerr << "exception catch: " << e.what() << "  " << __FILE__ << " - " << __FUNCTION__ << std::endl;
	}
	delete[] bigpoint;
	bigpoint = nullptr;
	std::cout << "finish test" << std::endl;
	return EXIT_SUCCESS;
}
