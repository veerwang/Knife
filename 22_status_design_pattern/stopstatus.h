#ifndef INCLUDED_STOPSTATUS_H
#define INCLUDED_STOPSTATUS_H

class StopStatus {
public:
	StopStatus();
	StopStatus(const StopStatus&);
	~StopStatus();
	
	virtual void Handle();
protected:
	
private:
	
};

#endif /* INCLUDED_STOPSTATUS_H */
