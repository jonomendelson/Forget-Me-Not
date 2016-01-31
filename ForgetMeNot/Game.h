#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Game {
	sf::RenderWindow * window;
public:
	void init(sf::RenderWindow *, Loader);

	
};

void Game::init(sf::RenderWindow * wind, Loader load) {
	window = wind;
}