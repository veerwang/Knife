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

template <int T>
struct enum2value
{
	enum { value = T };
};

// =====================================================================================

template <int T>
class Dispatch
{
private:
	void DoDispatch(enum2value<true> v)
	{
		std::cout<<"true Dispatch"<<std::endl;
	}
	void DoDispatch(enum2value<false> v)
	{
		std::cout<<"false Dispatch"<<std::endl;
	}
public:
	Dispatch() {;}
	~Dispatch() {;}
	void DoDispatch()
	{
		enum2value<T> v;
		DoDispatch(v);
	}
};

#endif /* !defined(INCLUDED_HEAD_H) */
