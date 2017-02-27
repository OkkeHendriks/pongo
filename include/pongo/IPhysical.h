#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "pongo/CDrawEvent.h"

class IPhysical
{
public:
	IPhysical() = default;
	~IPhysical() = default;


	virtual sf::VertexArray Draw() = 0;

	float x, y, a;
	float velX, velY, velA;

private:

};