/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  测试使用
 *
 *        Version:  1.0
 *        Created:  2021年06月07日
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

#include "basic.h"

void print_hello(int times) {
        for (int i = 0; i < times; i++) {
                std::cout << "hello the word" << std::endl;
        }
}

/*
 * ===  FUNCTION  =============================================================
 *         Name:  main
 *  Description:  程序的入口
 * ============================================================================
 */
int main(int argc, const char *argv[]) {
        std::cout << "hello" << std::endl;
        print_hello(2);
        if (true) {
                std::cout << "hello" << std::endl;
        }
        int num = 0;
        switch (num) {
                case 0:
                        std::cout << "hello" << std::endl;
                        break;
                default:
                        std::cout << "baby" << std::endl;
        }
        basic b;
        basic *c = new basic();
        c->disp_name();
        return EXIT_SUCCESS;
}
