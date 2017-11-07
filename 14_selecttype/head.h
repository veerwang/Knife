#if !defined(INCLUDED_HEAD_H)
#define INCLUDED_HEAD_H  1

/*
 * =====================================================================================
 *
 *       Filename:  head.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2017 10:57:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com
 *        Company:  Landicorp
 *   Organization:  GNU
 *
 * =====================================================================================
 */

template <typename T,typename U,bool flag>
struct selecttype 
{
	typedef T RefType;
};

template <typename T,typename U>
struct selecttype<T,U,false> 
{
	typedef U RefType;
};

template < typename T,bool flag >
struct DefineType
{
	typename selecttype<T,T*,flag>::RefType m_bp; // 注意此处 typename 的用法
};

// =====================================================================================

#endif /* !defined(INCLUDED_HEAD_H) */
