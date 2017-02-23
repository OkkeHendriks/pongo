#pragma once

#include "pongo/IComponent.h"
#include "pongo/CEventClient.h"
#include "pongo/CDrawEvent.h"

class IVisual : public IComponent
{
public:
	virtual ~IVisual() = default;

	// Forbid copying
	IVisual(IVisual const &) = delete;
	IVisual & operator=(IVisual const &) = delete;

private:


	// Inherited via IComponent
	virtual void update() override;

	CEventClient eventClient;
};

void IVisual::update()
{
	eventClient.subscribe<CDrawEvent>();
}
