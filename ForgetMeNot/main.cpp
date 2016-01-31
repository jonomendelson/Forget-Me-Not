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

sf::RenderWindow window(sf::VideoMode(1000, 800), "Forget-Me-Not", sf::Style::Close); //create window, sf::Style::Close means that the window can't be resized

Loader loader;
MainMenu mainMenu;
MultChoice multChoice;

void processKeystroke(char keystroke) {
	std::cout << "Processing " + keystroke;
}

void createFrame() {
	if (stage == "INIT") { //loading stage
		if (loader.loadResources() != 0) {
			MessageBox(NULL, L"Forget-Me-Not was not installed correctly, as files are missing.", L"Error.", NULL);
			exit(0);
		}
		else {
			mainMenu.init(&window, loader);
			multChoice.init(&window, loader, "What is 5*5?", "25", "15", "10", "5");
			stage = "MENU";
		}
	}
	else if (stage == "MENU") { //menu stage
		/*mainMenu.getInput(mouseX, mouseY, mouseDown, framesDisplayed);

		if (framesDisplayed == 30) { //triggers starting music
			loader.starting_music.play();
		}

		if (framesDisplayed < 340) { //flower start animation
			//framesDisplayed = 340; //REMOVE THIS LINE LATER (just to skip flower)
			mainMenu.displayFlower();
		}
		else{ //actual menu
			mainMenu.display();
		}*/
		multChoice.display();
		multChoice.getInput(mouseX, mouseY, mouseDown, framesDisplayed);
	}
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
				processKeystroke(static_cast<char>(event.text.unicode));
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