#include 	"runstatus.h"

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
 *         Name:  Handle 
 *  Description:  处理函数 
 * =====================================================================================
 */
void RunStatus::Handle() {
	std::cout << "RunStatus ..." << std::endl;
}
