/*
 * =============================================================================
 *
 *       Filename:  basic.cc
 *
 *    Description:  basic实现类
 *
 *        Version:  1.0
 *        Created:  2021年06月08日
 *       Revision:  1
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang
 *   Organization:
 *
 * =============================================================================
 */

#include "basic.h"

#include <iostream>

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  basic
 *  Description:  默认构造函数
 * =============================================================================
 */
basic::basic() {}

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  ~basic
 *  Description:  默认析构函数
 * =============================================================================
 */
basic::~basic() {}

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  basic
 *  Description:  拷贝构造函数
 * =============================================================================
 */
basic::basic(const basic& theclass) {}

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  disp_name
 *        Input:  void
 *       Output:
 *  Description:  函数说明文档
 * =============================================================================
 */
void basic::disp_name(void) {
        std::cout << "hello" << std::endl;
        std::cout << "hello" << std::endl;
}
