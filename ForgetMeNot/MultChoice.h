#pragma once

#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Loader.h"

class MultChoice {
	std::string question, answer, distractorOne, distractorTwo, distractorThree;
	sf::RenderWindow * window;

	int mouseX = 0;
	int mouseY = 0;
	bool mouseDown = false;
	int framesDisplayed = 0;

	Loader loader;
public:
	void init(sf::RenderWindow *, Loader, std::string, std::string, std::string, std::string, std::string);
	void getInput(int, int, bool, int);
	int display();
};

void MultChoice::init(sf::RenderWindow * wind, Loader load, std::string quest, std::string ans, std::string disOne, std::string disTwo, std::string disThree) {
	window = wind;
	loader = load;
	question = quest;
	answer = ans;
	distractorOne = disOne;
	distractorTwo = disTwo;
	distractorThree = disThree;
}

void MultChoice::getInput(int mouseXinput, int mouseYinput, bool mouseDowninput, int fdInput) {
	mouseX = mouseXinput;
	mouseY = mouseYinput;
	mouseDown = mouseDowninput;
	framesDisplayed = fdInput;
}

int MultChoice::display() {
	sf::Text menutitle;
	menutitle.setFont(loader.bold_font);
	menutitle.setCharacterSize(50);
	menutitle.setString(question);
	menutitle.setColor(sf::Color(0, 0, 0, 255));

	sf::FloatRect textRect = menutitle.getLocalBounds();
	menutitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	menutitle.setPosition(sf::Vector2f(1000 / 2.0f, 800 / 2.0f));
	
	(*window).draw(menutitle);


}