#include <memory>
#include <iostream>

#include "SFML\Graphics.hpp"
#include "pongo\CEventClient.h"
#include "pongo\CDrawEvent.h"


int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(700, 600), "Pongo!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	CEventPool eventPool;
	auto eventClient1 = std::make_shared<CEventClient>(eventPool);
	eventClient1->subscribe<CDrawEvent>();

	auto eventClient2 = std::make_shared<CEventClient>(eventPool);
	eventClient2->subscribe<CDrawEvent>();

	eventClient1->send(CDrawEvent(1));
	auto events = eventClient2->getEvents<CDrawEvent>();
	for (auto& event : events)
	{
		std::cout << event.mI << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
