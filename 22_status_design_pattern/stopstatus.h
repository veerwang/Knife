#ifndef INCLUDED_STOPSTATUS_H
#define INCLUDED_STOPSTATUS_H

#include 	"status.h"

class Context;

class StopStatus : public Status {
public:
	StopStatus();
	StopStatus(const StopStatus&);
	~StopStatus();
	
	virtual void Stop(Context* con);	
	virtual void Run(Context* con);	
protected:
	
private:
	
};

#endif /* INCLUDED_STOPSTATUS_H */
