/*
 * =====================================================================================
 *
 *       Filename:  dogobserver.cpp
 *
 *    Description:  特殊 
 *
 *        Version:  1.0
 *        Created:  2019年06月12日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 * *
 * =====================================================================================
 */

#include 	"dogobserver.h"
#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DogObserver
 *  Description:  默认构造函数 
 * =====================================================================================
 */
DogObserver::DogObserver () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~DogObserver
 *  Description:  默认析构函数 
 * =====================================================================================
 */
DogObserver::~DogObserver () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DogObserver  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
DogObserver::DogObserver(const DogObserver& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Update 
 *  Description:  更新状态
 * =====================================================================================
 */
void DogObserver::Update(Subject *sub) {
	mID = sub->getID();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Display 
 *  Description:  显示状态 
 * =====================================================================================
 */
void DogObserver::Display() {
	std::cout << "DogObserver: " << mID << std::endl;
}
