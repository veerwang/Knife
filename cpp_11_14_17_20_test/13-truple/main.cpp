/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年10月09日 
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

#include 	<tuple>
#include	<string>

std::tuple<int,std::string>
get_value() {
	return std::make_tuple(100,"kevin");
}

int 
main(int argc, const char *argv[]) {
	std::cout << "tuple test code" << std::endl;

	// C++ 17 的类型
	/*
	auto [x,y] = get_value();

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	*/

	// 如果用这种方式，就可以采用，优点是可以回传很多的数据，无需构造一个数据结构
	std::tuple<int,std::string> result = get_value();
	std::cout << std::get<0>(result) << std::endl;
	std::cout << std::get<1>(result) << std::endl;




	return EXIT_SUCCESS;
}
