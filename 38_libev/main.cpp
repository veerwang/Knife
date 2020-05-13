/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月13日 
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
#include 	<ev++.h>

ev_timer timeout_watcher; 	//定义一个timeout的观测者

/*
				//这是一个回调函数，用于定时器回调
static void 
timeout_cb(EV_P_ ev::ev_timer *w, int revents) {
	std::cout << "timeout" << std::endl;
        //这将导致最早运行的ev_run停止监听
	ev::ev_break(EV_A_ EVBREAK_ONE);
}
*/

int 
main(int argc, const char *argv[])
{
	std::cout << "libev library test" << std::endl;
	//使用一般默认的事件循环
	ev::default_loop loop;


	/*
	//初始化一个定时器watcher，然后启动它
	//只有一次，没有重复的5.5秒定时
	ev::ev_timer_init(&timeout_watcher, timeout_cb, 5.5, 0);
	ev::ev_timer_start(loop, &timeout_watcher);

	//这里开始loop，等待时间开始计时
	ev::ev_run(loop, 0);
	*/

	return EXIT_SUCCESS;
}
