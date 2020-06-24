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

class object {
public:
	/* 引入enum class 这样可以避免不同枚举类型之间的比较 */
	enum class opt_mod : unsigned int {
		save = 1,
		load = 2,
		del  = 3
	};

	object () {;}
	object (const object&) {;}
	virtual ~object() {;}

	/* opt mod */
	void set_mod(opt_mod mod) {
		m_mod = mod;
	}

protected:
	opt_mod m_mod;
	
private:
	
};

int main(int argc, const char *argv[]) {
	object obj;
	obj.set_mod(object::opt_mod::save);
	return EXIT_SUCCESS;
}
