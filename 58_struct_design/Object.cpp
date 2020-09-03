/*
 * =====================================================================================
 *
 *       Filename:  Object.cpp
 *
 *    Description:  实现 
 *
 *        Version:  1.0
 *        Created:  2020年09月03日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Object.h"
#include "Core.h"

#include <iostream>

/* 进行类型的显式实例化 */
/* 本测试例程的核心所在 */
template class Object<Core>;
template class Object<Msgbox>;
template class Object<Frame>;

template<>
void Object<Msgbox>::Display() {
	std::cout << "Msgbox Display" << std::endl;
}

template<>
void Object<Frame>::Display() {
	std::cout << "Frame Display" << std::endl;
}

template<typename T>
void Object<T>::Display() {
	std::cout << "Display" << std::endl;
}
