/*
 * =====================================================================================
 *
 *       Filename:  object.cpp
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2020年07月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "object.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  object
 *  Description:  默认构造函数 
 * =====================================================================================
 */
object::object () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~object
 *  Description:  默认析构函数 
 * =====================================================================================
 */
object::~object () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  object  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
object::object(const object& theclass) {
}
	
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getid 
 *  Description: 
 * =====================================================================================
 */
int object::getid() const {
	return _id;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  setid 
 *  Description: 
 * =====================================================================================
 */
void object::setid(int v) {
	_id = v + 99;
}