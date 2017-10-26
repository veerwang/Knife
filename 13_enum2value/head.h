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
struct int2value
{
	enum { value = T };
};

// =====================================================================================
// 关键是用Ｔ的数值进行不用函数的特化
template <int T>
class Dispatch
{
private:
	void DoDispatch(int2value<true>)		// 注意此处的用法，是个特化的类型
	{
		std::cout<<"true Dispatch"<<std::endl;
	}
	void DoDispatch(int2value<false>)
	{
		std::cout<<"false Dispatch"<<std::endl;
	}
public:
	Dispatch() {;}
	~Dispatch() {;}
	void DoDispatch()
	{
		DoDispatch(int2value<T>());		// 注意此处的用法,类型后面加上圆括号
	}
};

#endif /* !defined(INCLUDED_HEAD_H) */
