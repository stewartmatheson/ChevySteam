
#include "CityScape.h"
#include "SpriteLoader.h"
#include "Palatte.h"

int CityScape::main()
{
	Palette main("somewhere");

	SpriteLoader loader;
	loader.load();

	// load();
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	int width = 640;
	int height = 480;

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


