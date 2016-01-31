#include </usr/local/include/SFML/Graphics.hpp>
//#include <Windows.h>
#include <iostream>

#include "Game.h"
#include "Loader.h"
#include "MainMenu.h"

std::string stage = "INIT"; //different stages of program controlled by this variable

int mouseX = 0;
int mouseY = 0;

bool mouseDown;

int framesDisplayed = 0; //frame counter

sf::RenderWindow window(sf::VideoMode(1000, 800), "Forget-Me-Not", sf::Style::Close); //create window, sf::Style::Close means that the window can't be resized

Loader loader;
MainMenu mainMenu;

void createFrame() {
	if (stage == "INIT") { //loading stage
<<<<<<< Updated upstream
		if (loader.loadResources() != 0) {
			MessageBox(NULL, L"Forget-Me-Not was not installed correctly, as files are missing.", L"Error.", NULL);
=======
		if (loadResources() != 0) {
			//MessageBox(NULL, L"Forget-Me-Not was not installed correctly, as files are missing.", L"Error.", NULL);
>>>>>>> Stashed changes
			exit(0);
		}
		else {
			mainMenu.init(&window, loader);
			stage = "MENU";
		}
	}
	else if (stage == "MENU") { //menu stage
		mainMenu.getInput(mouseX, mouseY, mouseDown, framesDisplayed);
		if (framesDisplayed < 340) { //flower start animation
			mainMenu.displayFlower();
		}
		else { //actual menu
		/*	int menutitleopacity = 0;
			int menusubtitleopacity = 0;

			if (framesDisplayed > 435) {
				menutitleopacity = 255;
			}else if (framesDisplayed > 350) {
				menutitleopacity = (framesDisplayed - 350) * 3;
			}
			
			if (framesDisplayed > 535) {
				menusubtitleopacity = 255;
			}else if (framesDisplayed > 450) {
				menusubtitleopacity = (framesDisplayed - 450) * 3;
			}
		
			sf::Text menutitle;
			menutitle.setFont(bold_font);
			menutitle.setCharacterSize(75);
			menutitle.setString("Forget-Me-Not");
			menutitle.setPosition(sf::Vector2f(280, 10));
			menutitle.setColor(sf::Color(0, 0, 0, menutitleopacity));
			window.draw(menutitle);

			sf::Text menusubtitle;
			menusubtitle.setFont(bold_font);
			menusubtitle.setCharacterSize(24);
			menusubtitle.setString("A progess tracker for Alzheimers and Dementia patients. ");
			menusubtitle.setPosition(sf::Vector2f(220, 100));
			menusubtitle.setColor(sf::Color(0, 0, 0, menusubtitleopacity));
			window.draw(menusubtitle);



			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(450, 620));
			if (mouseX > 30 && mouseX < 480 && mouseY > 160 && mouseY < 780) {
				rect.setFillColor(sf::Color(255, 150, 150));
				if (mouseDown) {
					//madechoice
				}
			}
			else {
				rect.setFillColor(sf::Color(255, 120, 120));
			}
			rect.setPosition(sf::Vector2f(30, 160));
			window.draw(rect);

			sf::RectangleShape rect2;
			rect2.setSize(sf::Vector2f(450, 620));
			if (mouseX > 515 && mouseX < 965 && mouseY > 160 && mouseY < 780) {
				rect2.setFillColor(sf::Color(130, 200, 130));
				if (mouseDown) {
					//madechoice
				}
			}
			else {
				rect2.setFillColor(sf::Color(100, 200, 100));
			}
			rect2.setPosition(sf::Vector2f(515, 160));
			window.draw(rect2);

			

			//do buttons and shit*/
		}
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
		}

		mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);

		std::cout << "MouseX: " + std::to_string(mouseX) + " Mouse Y: " + std::to_string(mouseY) + "\n";

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