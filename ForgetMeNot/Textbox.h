#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

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

	std::string containedText = "";
public:
	bool isSelected = false;

	void init(sf::RenderWindow *, int, int);
	void getInput(int, int, bool, int);
	void display();
	void recieveChar(char);
};

void Textbox::init(sf::RenderWindow * actualWindow, int x, int y) {
	window = actualWindow;
	xPos = x;
	yPos = y;
}

void Textbox::getInput(int mouseXinput, int mouseYinput, bool mouseDowninput, int fdInput) {
	mouseX = mouseXinput;
	mouseY = mouseYinput;
	mouseDown = mouseDowninput;
	framesDisplayed = fdInput;
}

void Textbox::display() {
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(200, 200, 200, 255));
	rect.setSize(sf::Vector2f(xSize, ySize));
	rect.setPosition(sf::Vector2f(xPos, yPos));
	rect.setOutlineColor(sf::Color(180, 180, 180, 255));
	(*window).draw(rect);


	if (mouseDown) {
		if (mouseX > xPos && mouseX < xPos + xSize && mouseY > yPos && mouseY < yPos + ySize) { //clicked inside the box
			isSelected = true;
		}
		else {
			isSelected = false;
		}
	}
}

void Textbox::recieveChar(char inputChar) {
	containedText += inputChar;
}