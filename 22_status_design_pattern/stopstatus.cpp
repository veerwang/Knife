#include 	"stopstatus.h"
#include 	"context.h"

#include 	<iostream>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  StopStatus
 *  Description:  默认构造函数 
 * =====================================================================================
 */
StopStatus::StopStatus () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~StopStatus
 *  Description:  默认析构函数 
 * =====================================================================================
 */
StopStatus::~StopStatus () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  StopStatus  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
StopStatus::StopStatus(const StopStatus& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Stop 
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
void StopStatus::Stop(Context* con) {
	std::cout << "StopStatus stop" << std::endl;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Run 
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
void StopStatus::Run(Context* con) {
	std::cout << "StopStatus Run" << std::endl;
	ChangStatus(con,con->mRunStatus);
	con->Run();
}
