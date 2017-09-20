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
 *        Created:  09/20/2017 09:15:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com
 *        Company:  Landicorp
 *   Organization:  GNU
 *
 * =====================================================================================
 */

template< typename T >
class Base
{
public:
	Base();
	~Base();
	T m_ID;
};

template< typename T >
Base<T>::Base()
{

}

template< typename T >
Base<T>::~Base()
{

}

#endif /* !defined(INCLUDED_HEAD_H) */
