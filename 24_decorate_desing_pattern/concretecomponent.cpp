/*
 * =====================================================================================
 *
 *       Filename:  ConcreteComponent.cpp
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
 * *
 * =====================================================================================
 */
#include 	"concretecomponent.h"

#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ConcreteComponent
 *  Description:  默认构造函数 
 * =====================================================================================
 */
ConcreteComponent::ConcreteComponent () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~ConcreteComponent
 *  Description:  默认构造函数 
 * =====================================================================================
 */
ConcreteComponent::~ConcreteComponent () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Operation 
 *  Description:  实际操作 
 * =====================================================================================
 */
void ConcreteComponent::Operation() {
	std::cout << "Core Processing " << std::endl;
}
