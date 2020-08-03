/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月03日 
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
#include 	<cassert>

#include 	<pthread.h>
#include 	<sched.h>

static void 
api_show_thread_priority (pthread_attr_t *attr,int policy) {
	int priority = sched_get_priority_max (policy);
	assert (priority != -1);
	printf ("max_priority = %d\n", priority);
	priority = sched_get_priority_min (policy);
	assert (priority != -1);
	printf ("min_priority = %d\n", priority);
}

static int 
api_get_thread_policy (pthread_attr_t *attr) {
	int policy;
	int rs = pthread_attr_getschedpolicy (attr, &policy);
	assert (rs == 0);

	switch (policy)
	{
		case SCHED_FIFO:
			printf ("policy = SCHED_FIFO\n");
			break;
		case SCHED_RR:
			printf ("policy = SCHED_RR");
			break;
		case SCHED_OTHER:
			printf ("policy = SCHED_OTHER\n");
			break;
		default:
			printf ("policy = UNKNOWN\n");
			break; 
	}
	return policy;
}

static int 
api_get_thread_priority (pthread_attr_t *attr) {
    struct sched_param param;
    int rs = pthread_attr_getschedparam (attr, &param);
    assert (rs == 0);
    printf ("priority = %d\n", param.__sched_priority);
    return param.__sched_priority;
}

static void 
api_set_thread_policy (pthread_attr_t *attr,int policy) {
    int rs = pthread_attr_setschedpolicy (attr, policy);
    assert (rs == 0);
    api_get_thread_policy (attr);
}

int 
main(int argc, const char *argv[]) {
	std::cout << "thread prority test V1.0.0" << std::endl;	

	pthread_attr_t attr;       // 线程属性
	struct sched_param sched;  // 调度策略
	int rs;
	/* 
	 * 对线程属性初始化
	 * 初始化完成以后，pthread_attr_t 结构所包含的结构体
	 * 就是操作系统实现支持的所有线程属性的默认值
	 */
	rs = pthread_attr_init (&attr);
	assert (rs == 0);     // 如果 rs 不等于 0，程序 abort() 退出


	/* 获得当前调度策略 */
	int policy = api_get_thread_policy (&attr);

	/* 显示当前调度策略的线程优先级范围 */
	printf ("Show current configuration of priority\n");
	api_show_thread_priority(&attr, policy);

	/* 获取 SCHED_FIFO 策略下的线程优先级范围 */
	printf ("show SCHED_FIFO of priority\n");
	api_show_thread_priority(&attr, SCHED_FIFO);

	/* 获取 SCHED_RR 策略下的线程优先级范围 */
	printf ("show SCHED_RR of priority\n");
	api_show_thread_priority(&attr, SCHED_RR);

	/* 显示当前线程的优先级 */
	printf ("show priority of current thread\n");
	int priority = api_get_thread_priority (&attr);

	/* 手动设置调度策略 */
	printf ("Set thread policy\n");

	printf ("set SCHED_FIFO policy\n");
	api_set_thread_policy(&attr, SCHED_FIFO);

	printf ("set SCHED_RR policy\n");
	api_set_thread_policy(&attr, SCHED_RR);

	/* 还原之前的策略 */
	printf ("Restore current policy\n");
	api_set_thread_policy (&attr, policy);

	/* 
	 * 反初始化 pthread_attr_t 结构
	 * 如果 pthread_attr_init 的实现对属性对象的内存空间是动态分配的，
	 * phread_attr_destory 就会释放该内存空间
	 */
	rs = pthread_attr_destroy (&attr);
	assert (rs == 0);

	return EXIT_SUCCESS;
}
