/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行rcu类管理的代码
 *
 *        Version:  1.0
 *        Created:  2023年08月12日
 *       Revision:  1
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang
 *   Organization:
 *
 * =============================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

extern "C" void rcu_mrg_init(void);
extern "C" bool rcu_mrg_check_release(void);
extern "C" bool rcu_mrg_register(char* name);
extern "C" bool rcu_mrg_unregister(char* name);

int
main(int argc, const char *argv[]) {
	rcu_mrg_init();

	if (!rcu_mrg_register((char *)"GPIOA"))
		std::cout << "GPIOA register fail" << std::endl;

	if (!rcu_mrg_register((char *)"GPIOE"))
		std::cout << "GPIOE register fail" << std::endl;

	if (!rcu_mrg_unregister((char *)"GPIOA"))
		std::cout << "GPIOA register fail" << std::endl;

	if (!rcu_mrg_check_release())
		std::cout << "bad" << std::endl;

	return EXIT_SUCCESS;
}
