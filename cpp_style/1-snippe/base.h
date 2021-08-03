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
 *        Created:  2020年10月10日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

class Base {
  public:
	Base ();
	Base (const Base&);
	virtual ~Base();
	void Display();
	void GetID();

  protected:
	
  private:
	
};

#endif /* INCLUDED_BASE_H */
