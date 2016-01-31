#pragma once

#include <string>
#include <vector>
#
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

	std::vector<std::string> choices;
	int correctAns = 0;

	Loader loader;
public:
	void init(sf::RenderWindow *, Loader, std::string, std::string, std::string, std::string, std::string);
	void getInput(int, int, bool, int);
	void setupQuestion();
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

void MultChoice::setupQuestion() {
	correctAns = rand() % 4;
	
	int distractorOneLocation = correctAns;
	int distractorTwoLocation = correctAns;
	int distractorThreeLocation = correctAns;

	while (distractorOneLocation == correctAns) {
		distractorOneLocation = rand() % 4;
	}
	while (distractorTwoLocation == correctAns) {
		distractorTwoLocation = rand() % 4;
	}
	while (distractorThreeLocation == correctAns) {
		distractorThreeLocation = rand() % 4;
	}

	for (int i = 0; i < 4; i++) {
		if (i == correctAns) {
			choices.push_back(answer);
		}
		else if(i == distractorOneLocation){
			choices.push_back(distractorOne);
		}
		else if (i == distractorTwoLocation) {
			choices.push_back(distractorTwo);
		}
		else if (i == distractorThreeLocation) {
			choices.push_back(distractorThree);
		}
		
	}

}

int MultChoice::display() {
	int opacity = 255;
	srand(time(NULL));

	sf::Vector2u size = (*window).getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;

	sf::Text menutitle;
	menutitle.setFont(loader.bold_font);
	menutitle.setCharacterSize(50);
	menutitle.setString(question);
	menutitle.setColor(sf::Color(0, 0, 0, 255));

	sf::FloatRect textRect = menutitle.getLocalBounds();
	menutitle.setOrigin(textRect.left + textRect.width/ 2.0f, textRect.top + textRect.height / 2.0f);
	menutitle.setPosition(sf::Vector2f(1000 / 2.0f, 50.0f));

	(*window).draw(menutitle);

	//Rect1
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f((width / 2) - 15, (height / 4) - 20)); //half of the lower half of the height, with two spaces of 10 pts, one between, and one below

	if (mouseX > 10 && mouseX < 10 + rect.getSize().x && mouseY >(height / 2) && mouseY < (height / 2) + rect.getSize().y) {
		rect.setFillColor(sf::Color(255, 150, 150, opacity));
		if (mouseDown) {
			rect.setFillColor(sf::Color(120, 60, 60, opacity));
			if (correctAns == 0) return 1;
			else return -1;
		}
	}
	else {
		rect.setFillColor(sf::Color(255, 120, 120, opacity));
	}
	rect.setPosition(sf::Vector2f(10, (height / 2)));
	(*window).draw(rect);

	sf::Text text;
	text.setString(choices[0]);
	text.setPosition(sf::Vector2f(10 + 10, (height / 2) + (rect.getSize().y / 2) - 22));
	text.setCharacterSize(44);
	text.setColor(sf::Color(255, 255, 255, opacity));
	text.setFont(loader.bold_font);
	(*window).draw(text);

	//Rect2
	sf::RectangleShape rect2;
	rect2.setSize(sf::Vector2f((width / 2) - 15, (height / 4) - 20));

	if (mouseX > 10 && mouseX < 10 + rect2.getSize().x && mouseY >((height / 2) + rect.getSize().y + 10) && mouseY < ((height / 2) + rect.getSize().y + 10 + rect2.getSize().y)) {
		rect2.setFillColor(sf::Color(255, 150, 150, opacity));
		if (mouseDown) {
			rect2.setFillColor(sf::Color(120, 60, 60, opacity));
			if (correctAns == 1) return 1;
			else return -1;
		}
	}
	else {
		rect2.setFillColor(sf::Color(255, 120, 120, opacity));
	}
	rect2.setPosition(sf::Vector2f(10, (height / 2) + rect.getSize().y + 10));
	(*window).draw(rect2);

	sf::Text text2;
	text2.setString(choices[1]);
	text2.setPosition(sf::Vector2f(10 + 10, ((height / 2) + rect.getSize().y + 10) + (rect2.getSize().y / 2) - 22));
	text2.setCharacterSize(44);
	text2.setColor(sf::Color(255, 255, 255, opacity));
	text2.setFont(loader.bold_font);
	(*window).draw(text2);

	//Rect3
	sf::RectangleShape rect3;
	rect3.setSize(sf::Vector2f((width / 2) - 15, (height / 4) - 20));

	if (mouseX > 10 + rect.getSize().x + 10 && mouseX < 10 + rect.getSize().x + 10 + rect3.getSize().x && mouseY >(height / 2) && mouseY < (height / 2) + rect.getSize().y) {
		rect3.setFillColor(sf::Color(255, 150, 150, opacity));
		if (mouseDown) {
			rect3.setFillColor(sf::Color(120, 60, 60, opacity));
			if (correctAns == 2) return 1;
			else return -1;
		}
	}
	else {
		rect3.setFillColor(sf::Color(255, 120, 120, opacity));
	}
	rect3.setPosition(sf::Vector2f(10 + rect.getSize().x + 10, (height / 2)));
	(*window).draw(rect3);

	sf::Text text3;
	text3.setString(choices[2]);
	text3.setPosition(sf::Vector2f(10 + rect.getSize().x + 10 + 10, (height / 2) + (rect.getSize().y / 2) - 22));
	text3.setCharacterSize(44);
	text3.setColor(sf::Color(255, 255, 255, opacity));
	text3.setFont(loader.bold_font);
	(*window).draw(text3);

	//Rect4
	sf::RectangleShape rect4;
	rect4.setSize(sf::Vector2f((width / 2) - 15, (height / 4) - 20));

	if (mouseX > 10 + rect.getSize().x + 10 && mouseX < 10 + rect.getSize().x + 10 + rect3.getSize().x && mouseY >((height / 2) + rect.getSize().y + 10) && mouseY < ((height / 2) + rect.getSize().y + 10 + rect2.getSize().y)) {
		rect4.setFillColor(sf::Color(255, 150, 150, opacity));
		if (mouseDown) {
			rect4.setFillColor(sf::Color(120, 60, 60, opacity));
			if (correctAns == 3) return 1;
			else return -1;
		}
	}
	else {
		rect4.setFillColor(sf::Color(255, 120, 120, opacity));
	}
	rect4.setPosition(sf::Vector2f(10 + rect.getSize().x + 10, ((height / 2) + rect.getSize().y + 10)));
	(*window).draw(rect4);

	sf::Text text4;
	text4.setString(choices[3]);
	text4.setPosition(sf::Vector2f(10 + rect.getSize().x + 10 + 10, ((height / 2) + rect.getSize().y + 10) + (rect2.getSize().y / 2) - 22));
	text4.setCharacterSize(44);
	text4.setColor(sf::Color(255, 255, 255, opacity));
	text4.setFont(loader.bold_font);
	(*window).draw(text4);

	return 0;




	//window is 1000 by 800

}