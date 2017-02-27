#pragma once

#include <SFML\Graphics.hpp>

#include "pongo/IPhysical.h"

class CBall : public IPhysical
{
public:
	CBall()
	{
		mI = 0;
	}
	~CBall()
	{}


	virtual sf::VertexArray CBall::Draw() override
	{
		sf::VertexArray triangle(sf::Triangles, 3);

		// define the position of the triangle's points
		triangle[0].position = sf::Vector2f(10, 100 + 100*sin(0.001f*mI++));
		triangle[1].position = sf::Vector2f(100, 100);
		triangle[2].position = sf::Vector2f(100 + 50 * sin(0.001f*mI++), 200);

		// define the color of the triangle's points
		triangle[0].color = sf::Color::Red;
		triangle[1].color = sf::Color::Blue;
		triangle[2].color = sf::Color::Green;
		return triangle;
	}

private:
	int mI;

};
