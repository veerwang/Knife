#ifndef INCLUDED_DOGOBSERVER_H
#define INCLUDED_DOGOBSERVER_H

#include 	"subject.h"

class DogObserver {
public:
	DogObserver();
	DogObserver(const DogObserver&);
	~DogObserver();

	// 以subject为输入参数
	virtual void Update(Subject* );	
	
	void Display();
protected:
	
private:
};

#endif /* INCLUDED_DOGOBSERVER_H */
