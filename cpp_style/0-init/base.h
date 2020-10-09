#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H

/*
 * =====================================================================================
 *
 *       Filename:  base.h
 *
 *    Description:  基础类 
 *
 *        Version:  1.0
 *        Created:  2020年10月09日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "macro.inc"

namespace cppstyle {
class Base {
  public:
	Base ();
	Base (const Base&);
	virtual ~Base();

  protected:
	
  private:
	// 类成员变量以下划线结尾
	int id_ {100};
};
} /* namespace cppstyle */

#endif /* INCLUDED_BASE_H */
