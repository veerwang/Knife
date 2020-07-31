/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  测试用 
 *
 *        Version:  1.0
 *        Created:  2020年07月30日 
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

std::tuple<int,std::string> fun(int id) {
	return std::make_tuple(id + 100, "wangwei");
}

int main(int argc, const char *argv[]) {
	std::cout << "Test for coc plugin V1.0.0" << std::endl;	

	std::tuple<int,std::string> t(0,"kevin");

	/* 使用std::get函数来访问元素 */
	std::cout << std::get<0>(t) << std::endl;
	std::cout << std::get<1>(t) << std::endl;
	std::get<1>(t) = "veer";
	std::cout << std::get<1>(t) << std::endl;

	/* 通过make_tuple 生成元素 */
	t = std::make_tuple(100,"rita");
	std::cout << std::get<1>(t) << std::endl;

	/* 得到返回多个参数的内容,不用再使用struct来转换了 */
	auto a = fun(12);
	std::cout << std::get<0>(a) << std::endl;
	std::cout << std::get<1>(a) << std::endl;

	return EXIT_SUCCESS;
}
