/*
 * =====================================================================================
 *
 *       Filename:  templatehead.hpp
 *
 *    Description:  类模板实现 
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

#include <iostream>

namespace WangV {

template<typename id>
class Utils {
  public:
	Utils () { std::cout << "Utiles Create" << std::endl; }
	Utils (const Utils&) { std::cout << "Utils Create" << std::endl; }
	virtual ~Utils() { std::cout << "Utils Destroy" << std::endl; }

  protected:
	
  private:
};
} /* namespace WangV */

