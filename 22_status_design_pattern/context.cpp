#include 	"context.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Context
 *  Description:  默认构造函数 
 * =====================================================================================
 */
Context::Context () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~Context
 *  Description:  默认析构函数 
 * =====================================================================================
 */
Context::~Context () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Context  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
Context::Context(const Context& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Context  
 *  Description:  设置当前的状态 
 * =====================================================================================
 */
void Context::SetStatus( Status* s ) {
	mStatus = s;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitAllStatus
 *  Description:  初始化全部的状态
 * =====================================================================================
 */
void Context::InitAllStatus() {
	mRunStatus = new RunStatus();
	mStopStatus = new StopStatus();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ReleaseAllStatus 
 *  Description:  释放全部的状态 
 * =====================================================================================
 */
void Context::ReleaseAllStatus() {
	delete mRunStatus;
	delete mStopStatus;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Stop 
 *  Description:  处理函数 
 * =====================================================================================
 */
void Context::Stop() {
	mStatus->Stop(this);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Run 
 *  Description:  处理函数 
 * =====================================================================================
 */
void Context::Run() {
	mStatus->Run(this);
}