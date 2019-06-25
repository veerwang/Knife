#ifndef INCLUDED_PROXY_H
#define INCLUDED_PROXY_H

#include 	"subject.h"

class Proxy : public Subject {
public:
	Proxy();
	Proxy(const Proxy&);
	virtual ~Proxy();

	virtual void Request();

	void InitCore(Subject*);
protected:
	
private:
	Subject* _mSubject;
};

#endif /* INCLUDED_PROXY_H */
