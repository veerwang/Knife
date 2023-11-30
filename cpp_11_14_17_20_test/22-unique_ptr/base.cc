/*
 * =============================================================================
 *
 *       Filename:  base.cc
 *
 *    Description:  Base实现类 
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

#include "base.h"
#include <iostream>

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  Base
 *  Description:  默认构造函数 
 * =============================================================================
 */
Base::Base () {
	std::cout << "Base Create" << std::endl;
	mID = 100;
}

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ~Base
 *  Description:  默认析构函数 
 * =============================================================================
 */
Base::~Base () {
	std::cout << "Base Destroy" << std::endl;
}

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  Base 
 *  Description:  拷贝构造函数 
 * =============================================================================
 */
Base::Base(const Base& theclass) {
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  Display
 *  Description:  显示 
 * ============================================================================
 */
void Base::Display() {
	std::cout << "My Name = kevin" << " ID:" << mID << std::endl;
}
