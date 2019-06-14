/*
 * =====================================================================================
 *
 *       Filename:  boarddecorator.cpp
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

#include 	"boarddecorator.h"

#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BoardDecorator
 *  Description:  默认构造函数 
 * =====================================================================================
 */
BoardDecorator::BoardDecorator () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~BoardDecorator
 *  Description:  默认析构函数 
 * =====================================================================================
 */
BoardDecorator::~BoardDecorator () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BoardDecorator
 *  Description:  默认构造函数 
 * =====================================================================================
 */
BoardDecorator::BoardDecorator (Component* c) : Decorator(c) {

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Operation 
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
void BoardDecorator::Operation() {
	Decorator::Operation();
	std::cout << "BoardDecorator" << std::endl;
}
