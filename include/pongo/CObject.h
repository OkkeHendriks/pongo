#pragma once

#include <list>

#include "IComponent.h"

class CObject
{
public:
	CObject(std::list<IComponent> components);
	~CObject();

	void update(float dT);

private:
	std::list<IComponent> mComponents;
};