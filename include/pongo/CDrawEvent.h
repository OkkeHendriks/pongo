#pragma once
#include <SFML/Graphics.hpp>

// TODO: make templated event
class CDrawEvent
{
public:
	CDrawEvent(sf::VertexArray vertices)
		: mVertices(vertices)
	{		
	}

	~CDrawEvent()
	{
	}

	sf::VertexArray Get()
	{
		return mVertices;
	}


private:
	sf::VertexArray mVertices;
};

