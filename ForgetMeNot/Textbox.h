#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

#include "Loader.h"

class Textbox {
	sf::RenderWindow * window;

	int mouseX = 0;
	int mouseY = 0;
	bool mouseDown = false;
	int framesDisplayed = 0;

	int xPos = 0;
	int yPos = 0;
	int xSize = 500;
	int ySize = 50;

	Loader loader;
	sf::Clock clock;

	
	std::pair<std::string, int> processingStrokes;
public:
	bool isSelected = false;

	std::string containedText = "";

	void init(sf::RenderWindow *, Loader, int, int);
	void getInput(int, int, bool, int, std::pair<std::string, int>);
	void display();
};

void Textbox::init(sf::RenderWindow * actualWindow, Loader load, int x, int y) {
	loader = load;
	window = actualWindow;
	xPos = x;
	yPos = y;
}

void Textbox::getInput(int mouseXinput, int mouseYinput, bool mouseDowninput, int fdInput, std::pair<std::string, int> pStrokes) {
	mouseX = mouseXinput;
	mouseY = mouseYinput;
	mouseDown = mouseDowninput;
	framesDisplayed = fdInput;
	processingStrokes = pStrokes;
}

void Textbox::display() {
	if (isSelected) {
		containedText += processingStrokes.first;
	}
	processingStrokes.first = "";

	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(200, 200, 200, 255));
	rect.setOutlineColor(sf::Color(180, 180, 180, 255));
	rect.setOutlineThickness(2);
	rect.setSize(sf::Vector2f(xSize, ySize));
	rect.setPosition(sf::Vector2f(xPos, yPos));
	if(isSelected){
		rect.setOutlineColor(sf::Color(180, 50, 50, 255));
	}
	else {
		rect.setOutlineColor(sf::Color(180, 180, 180, 255));
	}
	(*window).draw(rect);

	if (isSelected) {

		if (containedText.length() >= processingStrokes.second) {
			for (int i = 0; i < processingStrokes.second; i++) {
				containedText.pop_back();
			}
		}
	}

	sf::Text text2;
	text2.setString(containedText);
	text2.setPosition(sf::Vector2f(xPos, yPos));
	text2.setCharacterSize(44);
	text2.setColor(sf::Color(255, 255, 255, 255));
	text2.setFont(loader.bold_font);
	(*window).draw(text2);

	if (mouseDown) {
		if (mouseX > xPos && mouseX < xPos + xSize && mouseY > yPos && mouseY < yPos + ySize) { //clicked inside the box
			isSelected = true;
		}
		else {
			isSelected = false;
		}
	}
	

	
}

