#ifndef INCLUDED_RUNSTATUS_H
#define INCLUDED_RUNSTATUS_H

#include 	"status.h"

class Context;

class RunStatus : public Status {
public:
	RunStatus();
	RunStatus(const RunStatus&);
	~RunStatus();

	virtual void Stop(Context* con);
	virtual void Run(Context* con);
protected:
	
private:
	
};

#endif /* INCLUDED_RUNSTATUS_H */
