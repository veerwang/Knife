/*
 * =====================================================================================
 *
 *       Filename:  decorator.cpp
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2019年06月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	"decorator.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Decorator
 *  Description:  默认构造函数 
 * =====================================================================================
 */
Decorator::Decorator () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~Decorator
 *  Description:  默认析构函数 
 * =====================================================================================
 */
Decorator::~Decorator () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Decorator  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
Decorator::Decorator(Component* c) {
	_mComponent = c;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Operation 
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
void Decorator::Operation() {
	_mComponent->Operation();
}



