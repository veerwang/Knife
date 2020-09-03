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

template class Object<Core>;
template class Object<Msgbox>;

template<>
void Object<Msgbox>::Display() {
	std::cout << "Msgbox Display" << std::endl;
}

template<typename T>
void Object<T>::Display() {
	std::cout << "Display" << std::endl;
}
