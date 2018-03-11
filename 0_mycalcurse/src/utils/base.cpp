/*
 * =====================================================================================
 *
 *       Filename:  base.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/2017 09:36:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com
 *        Company:  Landicorp
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include "base.h"
#include <iostream>

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Base
 * Description:  
 *--------------------------------------------------------------------------------------
 */
Base::Base ()
{
	std::cout<<"Create Base class"<<std::endl;
}  /* -----  end of method Base::Base  (constructor)  ----- */

Base::~Base ()
{
	std::cout<<"Destroy Base class"<<std::endl;
}  /* -----  end of method Base::Base  (destructor)  ----- */

