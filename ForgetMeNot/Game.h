#pragma once

#include </usr/local/include/SFML/Graphics.hpp>
//#include <SFML\Window.hpp>

class Game {
public:
	Game(sf::RenderWindow *);
};

Game::Game(sf::RenderWindow * window){
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Red);
	rect.setSize(sf::Vector2f(50, 50));
	(*window).draw(rect);
}