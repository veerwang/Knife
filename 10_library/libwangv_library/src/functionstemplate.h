#if !defined(INCLUDED_FUNCTIONS_HPP)
#define INCLUDED_FUNCTIONS_HPP  1

/*
 * =====================================================================================
 *
 *       Filename:  functionstemplate.hpp
 *
 *    Description:  保存一些神奇有用的模板 
 *
 *        Version:  1.0
 *        Created:  2015年02月13日 11时19分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <sstream>

namespace WangV
{

template <typename T>
std::string NumberToString ( T Number )
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

template <typename T>
std::string StringToNumber ( const std::string &Text )
{
	std::istringstream ss(Text);
	T result;	
	return ss >> result ? result : 0; 
}

template <typename T>
inline void deletep(T *p)
{
	if ( p != nullptr )
	{
		delete p;
		p = nullptr;
	}
}

}
#endif /* !defined(INCLUDED_FUNCTIONS_HPP) */
