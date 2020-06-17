/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月17日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 *       下载地址:  https://github.com/fmtlib/fmt
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>
#include	<ctime>

#include	<fmt/color.h>
#include	<fmt/format.h>

int main(int argc, const char *argv[]) {
	std::cout << "fmt testing" << std::endl;	
	std::string s = fmt::format("{0} ID:  0x{1:02x}","kevin",34);
	std::cout << s << std::endl;

	// 可以避免生成std::string类
	fmt::memory_buffer buf;
	fmt::format_to(buf, "{}\n", 42);
	fmt::format_to(buf, "{:x}\n", 42); // 十六进制表示
	std::cout << buf.data();

	// 打印字符串
	fmt::print("The answer is {}.\n", 42);

	// 打印生成错误码
	fmt::print(stderr, "System error code = {}\n", errno);

	// 可以有颜色显示
	using namespace fmt::literals;
	fmt::print(fg(fmt::color::red),"Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
			"name"_a="World", "number"_a=42);

	fmt::print("{}\n", std::numeric_limits<double>::infinity());

	std::time_t t = std::time(nullptr);
	std::localtime(&t);
	//fmt::print("The date is {:%Y-%m-%d}.\n", *std::localtime(&t));

	return EXIT_SUCCESS;
}
