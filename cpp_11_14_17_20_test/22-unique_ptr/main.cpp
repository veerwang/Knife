/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  unique_ptr使用
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
#include <memory>

#include "base.h"

void test1()
{
	// 重点，ptr是一个保存指针的变量，
	// 并且该指针的生命周期无需制定
	// 即无需显示释放
	std::unique_ptr<Base> ptr(new Base());
	// -> 可以访问内部的成员变量
	ptr->Display();
}

int main(int argc, const char* argv[])
{
	test1();
	return EXIT_SUCCESS;
}
