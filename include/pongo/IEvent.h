#pragma once
#include <list>

template <class T>
class IEvent
{
public:
	IEvent() 
	{}
	virtual ~IEvent()
	{}

	virtual T Get() = 0;
private:

};
