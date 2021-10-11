#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H

/*
 * =============================================================================
 *
 *       Filename:  base.h
 *
 *    Description:  base类 
 *
 *        Version:  1.0
 *        Created:  2021年10月11日 
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

	void Display();

  protected:
	
  private:
	
};

#endif /* INCLUDED_BASE_H */
