#include "pongo/CObject.h"

CObject::CObject(std::list<IComponent> components)
{
	mComponents = components
}

CObject::~CObject()
{
}

void CObject::update(float dT)
{
	for(auto& component :  mComponents)
	{
		component.update(dT);
	}
}
