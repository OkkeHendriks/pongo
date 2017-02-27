#include <memory>
#include <list>
#include <iostream>

#include "SFML\Graphics.hpp"

#include "pongo\CObject.h"
#include "pongo\CBall.h"
#include "pongo\CRenderer.h"

int main(int argc, char* argv[])
{
	CRenderer renderer;
	std::list<CObject> objects;
	
	objects.push_back(CObject({ std::make_shared<CBall>() }));
	while (renderer.isOpen())
	{
		renderer.update();
		for (auto& object : objects)
		{
			object.update(0.1f);
		}
		renderer.draw();

	}

	return 0;
}
