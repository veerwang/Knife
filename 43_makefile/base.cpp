/*
 * =====================================================================================
 *
 *       Filename:  base.cpp
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2020年06月11日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "base.h"
#include <iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  base
 *  Description:  默认构造函数 
 * =====================================================================================
 */
base::base () {
	std::cout << PRO_VERSION << std::endl;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~base
 *  Description:  默认析构函数 
 * =====================================================================================
 */
base::~base () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  base  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
base::base(const base& theclass) {
}
