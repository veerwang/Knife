#ifndef INCLUDED_MISCE_HPP
#define INCLUDED_MISCE_HPP

/*!
    \file    misce.hpp
    \brief   杂项内容

    \version 2024-02-17, V1.0
	\author	 kevin.wang
	\note    无
*/

#include 	<cstring>
#include	<algorithm>

namespace WangV {
/*!
	\brief			将数字转换成为字符串
	\param[in]		x 任意类型数值，例如int char long longlong double 	
	\param[out]		无
	\retval			转换后的字符串	
*/
template <typename T>
std::string number_to_string(T x) {
	std::string s;
	while (x) {
		s.push_back(x % 10 + '0');
		x /= 10;
	}
	std::reverse(s.begin(), s.end());
	return s;
}

} /* namespace WangV */

#endif /* INCLUDED_MISCE_HPP */
