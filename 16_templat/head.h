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

class Base
{
public:
	Base() {;}
	~Base() {;}
};

template <typename Baseclass = Base>
class Dispatch : public Baseclass
{
public:
	Dispatch() {;}
	~Dispatch() {;}
	static const int m_ID;
};

template <typename Baseclass>
const int Dispatch<Baseclass>::m_ID = 10;

#endif /* !defined(INCLUDED_HEAD_H) */
