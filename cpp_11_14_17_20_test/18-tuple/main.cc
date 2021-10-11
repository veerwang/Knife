/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  tuple的功能测试
 *
 *        Version:  1.0
 *        Created:  2021年10月11日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <tuple>

std::tuple<int, std::string> Function(int ID)
{
	std::tuple<int, std::string> result(0, " ");
	result = std::make_tuple(ID, "wwei");
	return result;
}

int main(int argc, const char* argv[])
{
	auto a = Function(100);
	std::cout << std::get<0>(a) << std::endl;
	return EXIT_SUCCESS;
}
