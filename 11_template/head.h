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

#include <cstdlib>
#include <cstdio>

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

/* ----------------------------------------------------------  */

template< typename T >
class BasePolicy
{
public:
	BasePolicy(){;}
	~BasePolicy(){;}

	void Fire()
	{
		std::cout<<"BasePolicy Fire"<<std::endl;
	}
};

template< typename T >
class MachinePolicy
{
public:
	MachinePolicy(){;}
	~MachinePolicy(){;}
	void Fire()
	{
		std::cout<<"MachinePolicy Fire"<<std::endl;
	}
};

/* ----------------------------------------------------------  */

template< typename T , typename BP = BasePolicy<T> >
class Gun
{
public:
	Gun() {;}
	~Gun(){;}

	void Trigger(){ BP bp; bp.Fire(); }
};

template< typename BC >
class Handle : public BC
{
public:
	Handle(){ std::cout<<"Handle create"<<std::endl; }
	virtual ~Handle(){ std::cout<<"Handle destroy"<<std::endl; }
};

/* ----------------------------------------------------------  */

/* CRTP */
template < typename T >
class SubHandle : public T
{
public:
	SubHandle() { std::cout<<"SubHandle create"<<std::endl; }
	virtual ~SubHandle() { std::cout<<"SubHandle create"<<std::endl; }
};

/* ----------------------------------------------------------  */

template <typename T>
class DefaultBase						// 注意类定义与实现是可以在h文件中的
{
public:
	DefaultBase(){;}
	~DefaultBase(){;}
};

template < template <typename> class BaseClass = DefaultBase >	// 注意T是可以省略的
class HostClass : public BaseClass<class T>			// 注意这里只能用class 而不能用typename
{
public:
	HostClass(){;}
	~HostClass(){;}
};

#endif /* !defined(INCLUDED_HEAD_H) */
