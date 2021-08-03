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

#include <cstdio>
#include <cstdlib>
#include <iostream>

/* 固定大小的数组 */
#include <array>

void Display() {
        std::cout << "kevin" << std::endl;
        std::cout << "hello the world" << std::endl;
}

int main(int argc, const char *argv[]) {
        std::cout << "array test V1.0.0" << std::endl;
        constexpr int maxlength = 10;
        std::array<int, maxlength> buf = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        for (auto e : buf) {
                std::cout << e << std::endl;
        }
        return EXIT_SUCCESS;
}
