#pragma once
#include <memory>

#include "CEventClient.h"
#include "CDrawEvent.h"


class CRenderer
{
public:
	CRenderer()
		: window(sf::VideoMode(700, 600), "Pongo!")
	{
		eventClient = CEventClient::create();
		eventClient->subscribe<CDrawEvent>();
	}
	~CRenderer()
	{}

	bool isOpen()
	{
		return window.isOpen();
	}

	void handleEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update()
	{
		handleEvents();
		window.clear(sf::Color::Black);
	}

	void draw()
	{
		auto drawEvents = eventClient->getMail<CDrawEvent>();
		while(!drawEvents.empty())
		{
			window.draw(drawEvents.front().Get());
			drawEvents.pop();
		}
		window.display();
	}

private:
	sf::RenderWindow window;
	std::shared_ptr<CEventClient> eventClient;
};
