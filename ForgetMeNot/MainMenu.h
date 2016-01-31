#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

#include "Loader.h"
#include "Textbox.h"

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
	void displayTitles();
	void displayFirstButtons(int);
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

void MainMenu::displayTitles() {
	int menutitleopacity = 0;
	int menusubtitleopacity = 0;

	if (framesDisplayed > 435) {
		menutitleopacity = 255;
	}
	else if (framesDisplayed > 350) {
		menutitleopacity = (framesDisplayed - 350) * 3;
	}

	if (framesDisplayed > 535) {
		menusubtitleopacity = 255;
	}
	else if (framesDisplayed > 450) {
		menusubtitleopacity = (framesDisplayed - 450) * 3;
	}

	sf::Text menutitle;
	menutitle.setFont(loader.bold_font);
	menutitle.setCharacterSize(75);
	menutitle.setString("Forget-Me-Not");
	menutitle.setPosition(sf::Vector2f(280, 10));
	menutitle.setColor(sf::Color(0, 0, 0, menutitleopacity));
	(*window).draw(menutitle);

	sf::Text menusubtitle;
	menusubtitle.setFont(loader.regular_font);
	menusubtitle.setCharacterSize(24);
	menusubtitle.setString("A progess tracker for Alzheimers and Dementia patients. ");
	menusubtitle.setPosition(sf::Vector2f(225, 100));
	menusubtitle.setColor(sf::Color(0, 0, 0, menusubtitleopacity));
	(*window).draw(menusubtitle);

	
	

}

void MainMenu::displayFirstButtons(int opacity) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(450, 620));
	if (mouseX > 30 && mouseX < 480 && mouseY > 160 && mouseY < 780) {
		rect.setFillColor(sf::Color(255, 150, 150, opacity));
		if (mouseDown) {
			rect.setFillColor(sf::Color(120, 60, 60, opacity));
			//create new patient
		}
	}
	else {
		rect.setFillColor(sf::Color(255, 120, 120, opacity));
	}
	rect.setPosition(sf::Vector2f(30, 160));
	(*window).draw(rect);

	sf::Text text;
	text.setString("CREATE NEW PATIENT");
	text.setPosition(sf::Vector2f(50, 420));
	text.setCharacterSize(44);
	text.setColor(sf::Color(255, 255, 255, opacity));
	text.setFont(loader.bold_font);
	(*window).draw(text);

	sf::RectangleShape rect2;
	rect2.setSize(sf::Vector2f(450, 620));
	if (mouseX > 515 && mouseX < 965 && mouseY > 160 && mouseY < 780) {
		rect2.setFillColor(sf::Color(130, 200, 130, opacity));
		if (mouseDown) {
			rect2.setFillColor(sf::Color(60, 100, 60, opacity));
			//load old patient
		}
	}
	else {
		rect2.setFillColor(sf::Color(100, 200, 100, opacity));
	}
	rect2.setPosition(sf::Vector2f(515, 160));
	(*window).draw(rect2);

	sf::Text text2;
	text2.setString("LOAD PATIENT DATA");
	text2.setPosition(sf::Vector2f(550, 420));
	text2.setCharacterSize(44);
	text2.setColor(sf::Color(255, 255, 255, opacity));
	text2.setFont(loader.bold_font);
	(*window).draw(text2);
}