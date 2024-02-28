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
#include 	<sstream>

namespace WangV {

/*!
	\brief			将数字转换成为字符串
	\param[in]		x 任意类型数值，例如int char long longlong double 	
	\param[out]		无
	\retval			转换后的字符串	
*/
template <typename T>
std::string number_to_string(T Number) {
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

/*!
	\brief			将字符串转换成为相应的数字
	\param[in]		std::string类型的字符串
	\param[out]		无
	\retval			数字	
*/
template <typename T>
T string_to_number(const std::string &Text)
{
	std::istringstream ss(Text);
	T result;	
	return ss >> result ? result : 0; 
}

/*!
	\brief			进行解构的类型
	\param[in]		无
	\param[out]		无
	\retval			无
*/
template <typename T>
inline void deletep(T *p)
{
	if ( p != nullptr ) {
		delete p;
		p = nullptr;
	}
}

template <typename T>
inline void deletearray(T *p)
{
	if ( p != nullptr ) {
		delete[] p;
		p = nullptr;
	}
}

/*!
	\brief			用于全局变量的设置与读取使用
	\param[in]		无
	\param[out]		无
	\retval			无
*/
template<typename T>
class Value
{
	public:
		Value(){;}
		Value(const T& v){ _value = v; }

		inline void set(const T value) 
		{ 
			_value = value;
		}
		inline T get() const
		{ return _value; }
	private:
		T _value;
};

} /* namespace WangV */

#endif /* INCLUDED_MISCE_HPP */
