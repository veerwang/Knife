/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月24日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>
#include	<memory>

class object {
public:
	object () { std::cout << "object create" << std::endl; }
	object (const object&) { ;}
	virtual ~object() { std::cout << "object destroy" << std::endl; }

	void display() { std::cout << "display object" << std::endl; }
protected:
	
private:
	
};

void test_ptr() {
	/* make_unique 只有在c++14才能使用 */
	std::unique_ptr<object> sp(std::make_unique<object>());
	/* 智能指针，如果生命周期结束了，会自动进行析构*/
	sp->display();
}

void move_ptr() {
	/* make_unique 只有在c++14才能使用 */
	std::unique_ptr<object> sp(std::make_unique<object>());
	/* 经过std::move操作之后，sp会变成nullptr指针 */
	std::unique_ptr<object> nsp(std::move(sp));
	nsp->display();

	if ( sp == nullptr )
		std::cout << "sp become nullptr" << std::endl;
	else
		std::cout << "OK" << std::endl;
}

int main(int argc, const char *argv[]) {
	std::cout << "memory test V1.0.0" << std::endl;
	test_ptr();
	move_ptr();
	std::cout << "memory test end"  << std::endl;
	return EXIT_SUCCESS;
}
