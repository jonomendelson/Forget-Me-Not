#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Loader.h"

class MainMenu {
	sf::RenderWindow * window;
	int mouseX = 0;
	int mouseY = 0;
	bool mouseDown = false;
	int framesDisplayed = 0;
	Loader loader;
public:
	void init(sf::RenderWindow *, Loader);
	void getInput(int, int, bool, int);
	void displayFlower();
};

void MainMenu::init(sf::RenderWindow * actualWindow, Loader loaderinput) {
	window = actualWindow;
	loader = loaderinput;
}

void MainMenu::getInput(int mouseXinput, int mouseYinput, bool mouseDowninput, int fdInput) {
	mouseX = mouseXinput;
	mouseY = mouseYinput;
	mouseDown = mouseDowninput;
	framesDisplayed = fdInput;
}

void MainMenu::displayFlower() {
	int opacity = 0;
	if (framesDisplayed > 213) {
		opacity = (framesDisplayed - 213) * -2 + 255;
	}
	else if (framesDisplayed > 93) {
		opacity = 255;
	}
	else if (framesDisplayed > 30) {
		opacity = (framesDisplayed - 30) * 4;
	}
	sf::Sprite logo;
	logo.setTexture(loader.logo_large_texture);
	logo.setScale(1, 1);
	logo.setPosition(sf::Vector2f(95, 0));
	logo.setColor(sf::Color(255, 255, 255, opacity));
	(*window).draw(logo);
}