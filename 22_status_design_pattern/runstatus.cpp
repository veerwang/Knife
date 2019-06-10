#include 	"runstatus.h"
#include 	"context.h"

#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  RunStatus
 *  Description:  默认构造函数 
 * =====================================================================================
 */
RunStatus::RunStatus () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~RunStatus
 *  Description:  默认析构函数 
 * =====================================================================================
 */
RunStatus::~RunStatus () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  RunStatus  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
RunStatus::RunStatus(const RunStatus& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Run 
 *  Description:  处理函数 
 * =====================================================================================
 */
void RunStatus::Run(Context* con) {
	std::cout << "RunStatus Run" << std::endl;
}
void RunStatus::Stop(Context* con) {
	std::cout << "RunStatus Stop" << std::endl;
	ChangStatus(con,con->mStopStatus);
	con->Stop();
}
