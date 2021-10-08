/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  函数尾部的定义 
 *
 *        Version:  1.0
 *        Created:  2021年10月08日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

// auto 这边的含义是，该函数的返回值由函数尾部的类型决定
template<typename T1, typename T2>
auto CreateFun(T1 x1, T2 x2) -> decltype(x1 + x2)
{
	return x1 + x2;
}

int 
main(int argc, const char *argv[]) {
	auto result = CreateFun(10,0.9);
	std::cout << result << std::endl;
	return EXIT_SUCCESS;
}
