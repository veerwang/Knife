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
class Core;

template <typename T=Core>
class Object : public T {
public:
	using T::T;

	void Display();
protected:

private:

};

#endif /* INCLUDED_OBJECT_H */
