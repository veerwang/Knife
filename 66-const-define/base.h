#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H

/*
 * =============================================================================
 *
 *       Filename:  base.h
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2021年09月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

class Base {
  public:
	Base ();
	Base (const Base&);
	virtual ~Base();

	void Disp();

	static const int MAXACCOUNT;
  protected:
	
  private:
};

#endif /* INCLUDED_BASE_H */
