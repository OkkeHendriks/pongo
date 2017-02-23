#pragma once
#include "IEvent.h"

class CDrawEvent : public IEvent<CDrawEvent>
{
public:
	CDrawEvent(int i);
	~CDrawEvent();
	int mI;
private:

	virtual CDrawEvent Get() override;

};

CDrawEvent::CDrawEvent(int i)
{
	mI = 0;
}

CDrawEvent::~CDrawEvent()
{
}

CDrawEvent CDrawEvent::Get()
{
	return *this;
}
