/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019年06月19日 
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

#include 	"component.h"
#include 	"composite.h"
#include 	"leaf.h"

int main(int argc, const char *argv[])
{
	std::cout << "compisite design patern" << std::endl;
	Composite* root = new Composite();
	Leaf*	   leaf1 = new Leaf();
	Leaf*	   leaf2 = new Leaf();

	root->AddComposite(leaf1);
	root->AddComposite(leaf2);

	std::cout << "Price:" << root->GetPrice() << std::endl;
	
	delete root;
	delete leaf2;
	delete leaf1;
	return EXIT_SUCCESS;
}
