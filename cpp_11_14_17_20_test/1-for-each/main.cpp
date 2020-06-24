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
#include 	<vector>
#include 	<algorithm>

class object {
public:
	object () {;}
	object (const object&) {;}

	object(int id) { ID = id; }
	virtual ~object() {;}

	void display() {
		std::cout << ID << std::endl;
	}
protected:
	
private:
	int ID;
};

void display(int e) {
	std::cout << e << std::endl;
}

int main(int argc, const char *argv[]) {
	std::cout << "for-each V1.0.0" << std::endl;
	constexpr int MAX = 5;
	int buf[MAX] = {1,2,3,4,5};

	for(auto x : buf) {
		std::cout << x << std::endl;
	}

	/* 注意这种初始化的方式 */
	object obj[3] = { 1,100,1000 };

	/* 注意这边一定要使用引用的方式 */
	for (auto &x : obj) {
		x.display();
	}

	std::vector<int> mydata;
	mydata.push_back(1);
	mydata.push_back(6);
	mydata.push_back(9);

	for(auto e : mydata) {
		std::cout << e << std::endl;
	}

	std::cout << "----" << std::endl;

	/* for_each的用法，注意需要#include <algorithm>*/
	for_each(mydata.begin(),mydata.end(),display);

	return EXIT_SUCCESS;
}
