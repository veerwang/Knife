#ifndef INCLUDED_OBSERVER_H
#define INCLUDED_OBSERVER_H

class Subject;

class Observer {
public:
	Observer();
	Observer(const Observer&);
	~Observer();

	// 以subject为输入参数
	virtual void Update(Subject* );	
protected:
	
private:
	
};

#endif /* INCLUDED_OBSERVER_H */
