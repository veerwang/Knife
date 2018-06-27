/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年03月23日 13时44分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>

class Gun
{
public:
	Gun() : m_ID(0), m_name("wangwei"), m_money(1000)
	{ ; }

	Gun( const  Gun& gun )
	{
		m_name 	= gun.m_name;
		m_ID   	= gun.m_ID - 6;
		m_money = gun.m_money - 1;
	}

	const Gun& operator= (const  Gun& gun)
	{
		this->m_name 	= gun.m_name;
		this->m_ID   	= gun.m_ID - 5;
		this->m_money   = gun.m_money - 2;
		return *this;
	}

	~Gun(){ ; }

	void set(int id)
	{
		m_ID = id;
	}

	void setname(std::string name)
	{
		m_name = name;
	}

	void setmoney(int money)
	{
		m_money = money;
	}

	void dada()
	{
		std::cout<<m_ID<<std::endl;
		std::cout<<m_name<<std::endl;
		std::cout<<m_money<<std::endl;
		std::cout<<"--------"<<std::endl;
	}
private:				// 默认的构造函数，私有成员变量会进行拷贝
	int 	    m_ID;
	int         m_money;
	std::string m_name;
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Gun sgun;			// 最最普通的初始化列表进行初始化
	sgun.dada();

	Gun gun;			// 被API函数进行改写
	gun.setname("gun");
	gun.set(20);
	gun.setmoney(10000);
	gun.dada();

	Gun mgun(sgun);			// 通过改写的拷贝构造函数
	mgun.dada();

	Gun ngun;			// 通过重载operator= 
	ngun = sgun;
	ngun.dada();

	Gun rgun = sgun;		// 与重载oprator=不同
	rgun.dada();			// Gun rgun = sgun 这种的写法与 Gun rgun(sgun) 相同
					// 这个是重点	是我认识到初始化的不同，一定要仔细去看

	/*
	Gun sgun = gun;
	sgun.setname("sgun");
	sgun.dada();

	Gun mgun(gun);
	mgun.dada();

	Gun hgun = gun;
	hgun.setname("hgun");
	hgun.dada();  */
	

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
