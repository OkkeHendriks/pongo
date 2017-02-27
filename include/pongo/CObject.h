#pragma once

#include <memory>
#include <list>


#include "pongo/CEventClient.h"
#include "IPhysical.h"

class CObject
{
public:
	CObject::CObject(std::shared_ptr<IPhysical> physical)
	{
		mPhysical = physical;
		mRenderClient = CEventClient::create();
	}

	CObject::~CObject()
	{
	}

	void CObject::update(float dT)
	{
		// Get current vertex postions
		sf::VertexArray vertices = mPhysical->Draw();

		// Update physics

		// Get 

		mRenderClient->post<CDrawEvent>(CDrawEvent(vertices));
	}


private:
	std::shared_ptr<IPhysical> mPhysical;
	std::shared_ptr<CEventClient> mRenderClient;

};