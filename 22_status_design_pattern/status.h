#ifndef INCLUDED_STATUS_H
#define INCLUDED_STATUS_H

class Context;

class Status {
public:
	Status();
	Status(const Status&);
	~Status();

	void ChangStatus(Context* con,Status* s);

	virtual void Stop(Context* con);	
	virtual void Run(Context* con);	
protected:
	
private:
	
};

#endif /* INCLUDED_STATUS_H */
