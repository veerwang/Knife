/*
 * =====================================================================================
 *
 *       Filename:  composite.cpp
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2019年06月20日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 * *
 * =====================================================================================
 */

#include 	"composite.h"

#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Composite
 *  Description:  默认构造函数 
 * =====================================================================================
 */
Composite::Composite () {
	mList.clear();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~Composite
 *  Description:  默认析构函数 
 * =====================================================================================
 */
Composite::~Composite () {
	while ( !mList.empty() ) {
		mList.pop_back();
	}
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Composite  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
Composite::Composite(const Composite& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  AddComposite
 *  Description:
 * =====================================================================================
 */
void Composite::AddComposite(Component* com) {
	mList.push_back(com);
	std::cout << "size = " << mList.size() << std::endl;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DelComposite
 *  Description:
 * =====================================================================================
 */
void Composite::DelComposite() {

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  GetPrice 
 *  Description:
 * =====================================================================================
 */
int Composite::GetPrice() {
	int result = 0;
	for ( std::list<Component*>::iterator p = mList.begin(); p!= mList.end(); p++ ) {
		result = (*p)->GetPrice();
	}
	return result;
}
