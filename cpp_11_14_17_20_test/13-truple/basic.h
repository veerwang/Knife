#ifndef INCLUDED_BASIC_H
#define INCLUDED_BASIC_H

/*
 * =============================================================================
 *
 *       Filename:  basic.h
 *
 *    Description:  basic 
 *
 *        Version:  1.0
 *        Created:  2021年11月03日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <tuple>
#include <string>

class Basic {
  public:
	Basic ();
	Basic (const Basic&);
	virtual ~Basic();

	std::tuple<std::string, int> GetValue();

  protected:
	
  private:
	
};

#endif /* INCLUDED_BASIC_H */
