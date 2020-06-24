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
	object () {
		for (int i=0;i<MAX;i++ ) {
			buf[i] = i;
		}
	}
	object (const object&) {;}
	virtual ~object() {;}

	/* constexptr 是常量表达式，const是常量 */
	static constexpr int MAX = 10;

	void display_buf() {
		for (int i=0;i<MAX;i++ ) {
			if ( int limit = 5; limit < i )
				std::cout << buf[i] << std::endl;
		}
	}
protected:
private:
	int buf[MAX];
};

/*
 *
 * 重点实验C++ 11 14 17 20 的一些特性
 * a. nullptr 指针为空,用来替换 NULL
 * b. constptr 替换 const
 * c. 在if/switch语句中，声明变量
 */

int main(int argc, const char *argv[]) {
	object *obj = new object();
	obj->display_buf();
	delete obj;
	obj = nullptr;
	return EXIT_SUCCESS;
}
