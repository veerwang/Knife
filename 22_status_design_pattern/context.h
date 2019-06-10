#ifndef INCLUDED_CONTEXT_H
#define INCLUDED_CONTEXT_H

#include 	"status.h"
#include 	"runstatus.h"
#include 	"stopstatus.h"

class Context {
public:
	Context();
	Context(const Context&);
	~Context();

	// 初始化全部的状态
	void InitAllStatus();
	void ReleaseAllStatus();

	// 设置当前状态指针
	void SetStatus( Status* s );	

	// 处理
	void Stop();	
	void Run();	
public:
	RunStatus* 	mRunStatus;
	StopStatus* 	mStopStatus;
protected:
	
private:
	// 当前的状态指针
	Status* 	mStatus;	
};

#endif /* INCLUDED_CONTEXT_H */
