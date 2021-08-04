/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  用于测试clang-format工具
 *
 *        Version:  1.0
 *        Created:  2021年08月03日
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

extern "C" int GetVersion();

int main(int argc, const char *argv[]) {
        Basic b;
        std::cout << "hello the world" << std::endl;
        b.Display();
        std::cout << GetVersion() << std::endl;
        return EXIT_SUCCESS;
}
