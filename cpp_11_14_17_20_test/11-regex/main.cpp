/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月24日 
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
#include	<regex>

int
main(int argc, const char *argv[]) {
	std::cout << "regex test V1.0.0" << std::endl;

	std::string fnames[] = { "abc.txt","ccc.txt","wang.txt" };
	std::regex text_regex("[a-z]*c\\.txt");

	// 在 C ++ 中 \ 会 被 作 为 字 符 串 内 的 转 义 符 , 为 使 \. 作 为 正 则 表 达 式 传 递 进 去 生 效 , 需 要 对 \ 进 行 二 次 转 义 , 从 而 有 \\.

	for( const auto &fname : fnames ) {
		std::cout << fname << ":" << std::regex_match(fname,text_regex) << std::endl;
	}

	return EXIT_SUCCESS;
}
