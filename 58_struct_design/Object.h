#ifndef INCLUDED_OBJECT_H
#define INCLUDED_OBJECT_H

/*
 * =====================================================================================
 *
 *       Filename:  Object.h
 *
 *    Description:  类介绍 
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
#include "Core.h"

template <typename T=Core>
class Object : public T {
public:
	using T::T;

	void Display();
protected:

private:

};

template<typename T>
void Object<T>::Display() {
	std::cout << "Display" << std::endl;
}

template<Msgbox>
void Object<>::Display() {
	std::cout << "Msgbox Display" << std::endl;
}

#endif /* INCLUDED_OBJECT_H */
