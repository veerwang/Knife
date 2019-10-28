/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: for_each 
 *
 *        Version:  1.0
 *        Created:  2018年11月23日 13时44分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory>
#include <typeinfo>

class Base {
public:
	Base() { m_ID = 0;std::cout << "Base Create" << std::endl; };
	Base(const Base&);
	virtual ~Base() { std::cout << "Base Destroy" << std::endl; };
	
	void Display() { std::cout << "Base Display: " << m_ID << std::endl; };
	void SetID(int id) { m_ID =  id; };
protected:
	
private:
	int m_ID;
	
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
	// 自动指针，会自行进行析构
	std::unique_ptr<Base> ppoint( new Base() );
	ppoint->Display();
	ppoint->SetID(20);
	ppoint->Display();

	// 注意此处 ppoint调用get的用法，是句点的方式不是->方式
	Base* newpoint = ppoint.get();
	newpoint->SetID(100);
	newpoint->Display();
	ppoint->Display();

	// 注意，此处会将原先的变量进行销毁，在重新初始化
	ppoint.reset( new Base());
	// 如果仅仅是ppoint.reset()，那么就是删除之前的变量，并且不进行新变量的创建
	ppoint->Display();

	Base* happypoint = ppoint.release();
	// now ppoint是nullpoint
	happypoint->Display();

	if (ppoint == nullptr)
		std::cout << "nullptr,can't call it" << std::endl;

	return EXIT_SUCCESS;
}
