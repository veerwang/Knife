#ifndef INCLUDED_RUNSTATUS_H
#define INCLUDED_RUNSTATUS_H

#include 	"status.h"

class RunStatus : public Status {
public:
	RunStatus();
	RunStatus(const RunStatus&);
	~RunStatus();

	virtual void Handle();
	
protected:
	
private:
	
};

#endif /* INCLUDED_RUNSTATUS_H */
