/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月11日 
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

/* version V1.0.0 */
void 
display_version() {
	std::cout << "This version V1.0.0" << std::endl;
}

void 
do_action() {
	std::cout << "Do action start" << std::endl;
}

/* 由于该函数没有导出，因此不能被其他模块调用 */
void 
private_function() {

	std::cout << "private function" << std::endl;
}
