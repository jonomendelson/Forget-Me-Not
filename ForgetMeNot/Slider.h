#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Loader.h"


class Slider {
	sf::RenderWindow * window;

	int mouseX = 0;
	int mouseY = 0;
	bool mouseDown = false;
	int framesDisplayed = 0;

	Loader loader;

	int xPos = 0;
	int yPos = 0;
	
	int isSelected = false;
public:

	int number = 5;
	void init(sf::RenderWindow *, Loader, int, int);
	void getInput(int, int, bool, int);
	void display();


};

void Slider::init(sf::RenderWindow * wind, Loader load, int xPosinput, int yPosinput) {
	window = wind;
	loader = load;
	xPos = xPosinput;
	yPos = yPosinput;
}

void Slider::getInput(int mouseXinput, int mouseYinput, bool mouseDowninput, int fdInput) {
	mouseX = mouseXinput;
	mouseY = mouseYinput;
	mouseDown = mouseDowninput;
	framesDisplayed = fdInput;
}

void Slider::display() {
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(150, 150, 150, 255));
	rect.setSize(sf::Vector2f(710, 20));
	rect.setPosition(sf::Vector2f(xPos, yPos));
	(*window).draw(rect);

	sf::RectangleShape tab;
	tab.setFillColor(sf::Color(50, 50, 50, 255));
	tab.setSize(sf::Vector2f(30, 70));
	tab.setPosition(sf::Vector2f(xPos+75*number-80, yPos-35));
	(*window).draw(tab);

	if (mouseDown) {
		if (mouseX > xPos + 75 * number - 80 && mouseX < xPos + 75 * number - 80 + 30 && mouseY > yPos - 35 && mouseY < yPos - 35 + 100) {
			isSelected = true;
		}
	}
	else {
		isSelected = false;
	}

	if (isSelected == true) {
		number = (int)((mouseX - xPos + 30) / 75) + 1;
		if (number < 1) {
			number = 1;
		}
		if (number > 10) {
			number = 10;
		}
		std::cout << std::to_string(number);
	}

	
	sf::Text text;
	text.setFont(loader.regular_font);
	text.setPosition(xPos, yPos+30);
	text.setString("1\t2\t3\t4\t5\t6\t7\t8\t9\t10");
	text.setColor(sf::Color::Black);
	text.setCharacterSize(48);
	(*window).draw(text);
}