/*
 * =====================================================================================
 *
 *       Filename:  concretsubject.cpp
 *
 *    Description:  具体的subject类 
 *
 *        Version:  1.0
 *        Created:  2019年06月12日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	"concretsubject.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ConcretSubject
 *  Description:  默认构造函数 
 * =====================================================================================
 */
ConcretSubject::ConcretSubject () {
	mID = 1;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~ConcretSubject
 *  Description:  默认析构函数 
 * =====================================================================================
 */
ConcretSubject::~ConcretSubject () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ConcretSubject  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
ConcretSubject::ConcretSubject(const ConcretSubject& theclass) {
}
