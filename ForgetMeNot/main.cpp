#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Windows.h>
#include <iostream>

#include "Game.h"
#include "Loader.h"
#include "MainMenu.h"
#include "Textbox.h"
#include "MultChoice.h"

std::string stage = "INIT"; //different stages of program controlled by this variable

int mouseX = 0;
int mouseY = 0;

bool mouseDown;

int framesDisplayed = 0; //frame counter

std::pair<std::string, int> processingStrokes;

Patient currPatient;

sf::RenderWindow window(sf::VideoMode(1000, 800), "Forget-Me-Not", sf::Style::Close); //create window, sf::Style::Close means that the window can't be resized

Loader loader;
MainMenu mainMenu;

void createFrame() {
	if (stage == "INIT") { //loading stage
		if (loader.loadResources() != 0) {
			MessageBox(NULL, L"Forget-Me-Not was not installed correctly, as files are missing.", L"Error.", NULL);
			exit(0);
		}
		else {
			mainMenu.init(&window, loader);
			stage = "MENU";
		}
	}
	else if (stage == "MENU") { //menu stage
		mainMenu.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);

		if (framesDisplayed == 30) { //triggers starting music
			loader.starting_music.play();
		}

		if (framesDisplayed < 340) { //flower start animation
			//framesDisplayed = 340; //REMOVE THIS LINE LATER (just to skip flower)
			mainMenu.displayFlower();
		}
		else{ //actual menu
			int isDisplay = mainMenu.display();
			if (isDisplay == 1) {
				currPatient = mainMenu.getPatient();
				stage = "OPTIONS";
			}
		}
	}
	else if (stage == "OPTIONS") {
		sf::Text menutitle;
		menutitle.setFont(loader.bold_font);
		menutitle.setCharacterSize(75);
		menutitle.setString("Forget-Me-Not");
		menutitle.setPosition(sf::Vector2f(280, 10));
		menutitle.setColor(sf::Color(0, 0, 0, 255));
		window.draw(menutitle);

		sf::Text menusubtitle;
		menusubtitle.setFont(loader.regular_font);
		menusubtitle.setCharacterSize(24);
		menusubtitle.setString("Loaded patient " + currPatient.firstName + " " + currPatient.lastName);
		menusubtitle.setPosition(sf::Vector2f(300, 100));
		menusubtitle.setColor(sf::Color(0, 0, 0, 255));
		window.draw(menusubtitle);

		int choice = 0;

		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(450, 620));
		if (mouseX > 30 && mouseX < 480 && mouseY > 160 && mouseY < 780) {
			rect.setFillColor(sf::Color(255, 150, 150, 255));
			if (mouseDown) {
				rect.setFillColor(sf::Color(120, 60, 60, 255));
				choice = 1;
			}
		}
		else {
			rect.setFillColor(sf::Color(255, 120, 120, 255));
		}
		rect.setPosition(sf::Vector2f(30, 160));
		window.draw(rect);

		sf::Text text;
		text.setString("START NEW TEST");
		text.setPosition(sf::Vector2f(50, 420));
		text.setCharacterSize(44);
		text.setColor(sf::Color(255, 255, 255, 255));
		text.setFont(loader.bold_font);
		window.draw(text);

		sf::RectangleShape rect2;
		rect2.setSize(sf::Vector2f(450, 620));
		if (mouseX > 515 && mouseX < 965 && mouseY > 160 && mouseY < 780) {
			rect2.setFillColor(sf::Color(130, 200, 130, 255));
			if (mouseDown) {
				rect2.setFillColor(sf::Color(60, 100, 60, 255));
				choice = 2;
			}
		}
		else {
			rect2.setFillColor(sf::Color(100, 200, 100, 255));
		}
		rect2.setPosition(sf::Vector2f(515, 160));
		window.draw(rect2);

		sf::Text text2;
		text2.setString("VIEW PATIENT RESULTS");
		text2.setPosition(sf::Vector2f(550, 420));
		text2.setCharacterSize(44);
		text2.setColor(sf::Color(255, 255, 255, 255));
		text2.setFont(loader.bold_font);
		window.draw(text2);

		if (choice == 1) {
			stage = "GAME";
		}
	}
	else if (stage == "GAME") {

	}

	processingStrokes.first = "";
	processingStrokes.second = 0;
	std::cout << "\n";
}


int main() {
	sf::Clock frameTimer;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseMoved) {
				mouseX = sf::Mouse::getPosition(window).x;
				mouseY = sf::Mouse::getPosition(window).y;
			}
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode == 8) {
					processingStrokes.second += 1;
					std::cout << std::to_string(processingStrokes.second);
					
				}
				else {
					processingStrokes.first.push_back(static_cast<char>(event.text.unicode));
				}
			}
		}

		mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);

		sf::Time elapsedSinceLastFrame = frameTimer.getElapsedTime();

		if (elapsedSinceLastFrame.asMilliseconds() > 16) { //60 fps
			window.clear(sf::Color::White);
			createFrame();
			window.display();

			framesDisplayed++;
			frameTimer.restart();
		}
	}

	return 0;
}