#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

#include "Loader.h"
#include "Textbox.h"
#include "Slider.h"
#include "Patient.h"

class MainMenu {
	sf::RenderWindow * window;
	int mouseX = 0;
	int mouseY = 0;
	bool mouseDown = false;
	int framesDisplayed = 0;

	std::string stage = "OUTER";
	std::pair<std::string, int> processingStrokes;

	Textbox firstNameTextbox;
	Textbox lastNameTextbox;
	Textbox ageTextbox;
	Textbox birthdayTextbox;
	Textbox carepersonemailTextbox;
	Slider levelofalzSlider;

	Loader loader;

	Patient currPatient;
public:
	void init(sf::RenderWindow *, Loader);
	void getInput(int, int, bool, int, std::pair<std::string, int>);
	void displayFlower();
	void display();
	void displayTitles();
	int displayFirstButtons(int);
	void displayPatientForm();
	void displayFamilyForm();
};

void MainMenu::init(sf::RenderWindow * actualWindow, Loader loaderinput) {
	window = actualWindow;
	loader = loaderinput;
}

void MainMenu::getInput(int mouseXinput, int mouseYinput, bool mouseDowninput, int fdInput, std::pair<std::string, int> pStrokes) {
	mouseX = mouseXinput;
	mouseY = mouseYinput;
	mouseDown = mouseDowninput;
	framesDisplayed = fdInput;
	processingStrokes = pStrokes;
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

void MainMenu::display() {
	std::cout << processingStrokes.first;
	if (stage == "OUTER") {
		displayTitles();
		
		int result = 0;

		if (framesDisplayed < 575 && framesDisplayed > 490) {
			int opacity = (framesDisplayed - 490) * 3;
			result = displayFirstButtons(opacity);
		}
		else if (framesDisplayed > 574) {
			result = displayFirstButtons(255);
		}

		result = 1;

		if (result == 1) {
			firstNameTextbox.init(window, loader, 250, 100);
			lastNameTextbox.init(window, loader, 250, 175);
			ageTextbox.init(window, loader, 250, 250);
			birthdayTextbox.init(window, loader, 250, 325);
			carepersonemailTextbox.init(window, loader, 250, 400);
			levelofalzSlider.init(window, loader, 250, 525);
			stage = "CREATE_NEW";
		}
		else if (result == 2) {
			stage = "LOAD";
		}
	}
	else if (stage == "CREATE_NEW") {
		displayPatientForm();
	}
	else if (stage == "IMPORT_FAMILY") {
		displayFamilyForm();
	}
	processingStrokes.first = "";
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

int MainMenu::displayFirstButtons(int opacity) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(450, 620));
	if (mouseX > 30 && mouseX < 480 && mouseY > 160 && mouseY < 780) {
		rect.setFillColor(sf::Color(255, 150, 150, opacity));
		if (mouseDown) {
			rect.setFillColor(sf::Color(120, 60, 60, opacity));
			return 1;
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
			return 2;
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
	return 0;
}

void MainMenu::displayPatientForm() {
	sf::Text text2;
	text2.setString("Create New Patient");
	text2.setPosition(sf::Vector2f(300, 10));
	text2.setCharacterSize(48);
	text2.setColor(sf::Color(0, 0, 0, 255));
	text2.setFont(loader.bold_font);
	(*window).draw(text2);

	sf::Text firstNameText;
	firstNameText.setString("First Name: ");
	firstNameText.setPosition(sf::Vector2f(20, 100));
	firstNameText.setCharacterSize(36);
	firstNameText.setColor(sf::Color(0, 0, 0, 255));
	firstNameText.setFont(loader.regular_font);
	(*window).draw(firstNameText);

	sf::Text lastNameText;
	lastNameText.setString("Last Name: ");
	lastNameText.setPosition(sf::Vector2f(20, 175));
	lastNameText.setCharacterSize(36);
	lastNameText.setColor(sf::Color(0, 0, 0, 255));
	lastNameText.setFont(loader.regular_font);
	(*window).draw(lastNameText);

	sf::Text ageText;
	ageText.setString("Age: ");
	ageText.setPosition(sf::Vector2f(20, 250));
	ageText.setCharacterSize(36);
	ageText.setColor(sf::Color(0, 0, 0, 255));
	ageText.setFont(loader.regular_font);
	(*window).draw(ageText);

	sf::Text birthdayText;
	birthdayText.setString("Birthday: ");
	birthdayText.setPosition(sf::Vector2f(20, 325));
	birthdayText.setCharacterSize(36);
	birthdayText.setColor(sf::Color(0, 0, 0, 255));
	birthdayText.setFont(loader.regular_font);
	(*window).draw(birthdayText);

	sf::Text emailTextbox;
	emailTextbox.setString("Caretaker's Email: ");
	emailTextbox.setPosition(sf::Vector2f(20, 405));
	emailTextbox.setCharacterSize(32);
	emailTextbox.setColor(sf::Color(0, 0, 0, 255));
	emailTextbox.setFont(loader.regular_font);
	(*window).draw(emailTextbox);

	sf::Text alzLevelText;
	alzLevelText.setString("Starting Question Difficulty: ");
	alzLevelText.setPosition(sf::Vector2f(20, 525));
	alzLevelText.setCharacterSize(18);
	alzLevelText.setColor(sf::Color(0, 0, 0, 255));
	alzLevelText.setFont(loader.regular_font);
	(*window).draw(alzLevelText);

	firstNameTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);
	lastNameTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);
	ageTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);
	birthdayTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);
	carepersonemailTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);
	levelofalzSlider.getInput(mouseX, mouseY, mouseDown, framesDisplayed);

	firstNameTextbox.display();
	lastNameTextbox.display();
	ageTextbox.display();
	birthdayTextbox.display();
	carepersonemailTextbox.display();
	levelofalzSlider.display();

	sf::RectangleShape nextButton;
	nextButton.setSize(sf::Vector2f(200, 75));
	if (mouseX > 700 && mouseX < 900 && mouseY > 700 && mouseY < 775) {
		nextButton.setFillColor(sf::Color(255, 150, 150, 255));
		if (mouseDown) {
			nextButton.setFillColor(sf::Color(120, 60, 60, 255));
			if (firstNameTextbox.containedText != "" && lastNameTextbox.containedText != "" && ageTextbox.containedText != "" && birthdayTextbox.containedText != "" && carepersonemailTextbox.containedText != "") {
				currPatient.createPatient(firstNameTextbox.containedText, lastNameTextbox.containedText, std::stoi(ageTextbox.containedText), birthdayTextbox.containedText, carepersonemailTextbox.containedText, levelofalzSlider.number);
				firstNameTextbox.containedText = "";
				lastNameTextbox.containedText = "";
				stage = "IMPORT_FAMILY";
			}
		}
	}
	else {
		nextButton.setFillColor(sf::Color(255, 120, 120, 255));
	}
	nextButton.setPosition(sf::Vector2f(700, 700));
	(*window).draw(nextButton);

	sf::Text nextText;
	nextText.setString("Next >");
	nextText.setPosition(sf::Vector2f(720, 700));
	nextText.setCharacterSize(64);
	nextText.setColor(sf::Color(255, 255, 255, 255));
	nextText.setFont(loader.regular_font);
	(*window).draw(nextText);

	stage = "IMPORT_FAMILY"; //delete
}

void MainMenu::displayFamilyForm() {
	sf::Text text2;
	text2.setString("Import Family Information");
	text2.setPosition(sf::Vector2f(270, 10));
	text2.setCharacterSize(48);
	text2.setColor(sf::Color(0, 0, 0, 255));
	text2.setFont(loader.bold_font);
	(*window).draw(text2);

	sf::Text subtitle;
	subtitle.setString("Import up to 5 family members. If you don't want to import any more, leave their names blank.");
	subtitle.setPosition(sf::Vector2f(35, 60));
	subtitle.setCharacterSize(24);
	subtitle.setColor(sf::Color(0, 0, 0, 255));
	subtitle.setFont(loader.regular_font);
	(*window).draw(subtitle);

	sf::Text firstNameText;
	firstNameText.setString("First Name: ");
	firstNameText.setPosition(sf::Vector2f(20, 100));
	firstNameText.setCharacterSize(36);
	firstNameText.setColor(sf::Color(0, 0, 0, 255));
	firstNameText.setFont(loader.regular_font);
	(*window).draw(firstNameText);

	sf::Text relationText;
	relationText.setString("Relation to patient: ");
	relationText.setPosition(sf::Vector2f(20, 180));
	relationText.setCharacterSize(24);
	relationText.setColor(sf::Color(0, 0, 0, 255));
	relationText.setFont(loader.regular_font);
	(*window).draw(relationText);

	firstNameTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);
	lastNameTextbox.getInput(mouseX, mouseY, mouseDown, framesDisplayed, processingStrokes);

	firstNameTextbox.display();
	lastNameTextbox.display();

	sf::RectangleShape browseButton;
	browseButton.setSize(sf::Vector2f(250, 50));
	if (mouseX > 50 && mouseX < 300 && mouseY > 250 && mouseY < 300) {
		browseButton.setFillColor(sf::Color(255, 150, 150, 255));
		if (mouseDown) {
			browseButton.setFillColor(sf::Color(120, 60, 60, 255));
			if (firstNameTextbox.containedText != "" && lastNameTextbox.containedText != "" && ageTextbox.containedText != "" && birthdayTextbox.containedText != "" && carepersonemailTextbox.containedText != "") {
				currPatient.createPatient(firstNameTextbox.containedText, lastNameTextbox.containedText, std::stoi(ageTextbox.containedText), birthdayTextbox.containedText, carepersonemailTextbox.containedText, levelofalzSlider.number);
				firstNameTextbox.containedText = "";
				lastNameTextbox.containedText = "";
				stage = "IMPORT_FAMILY";
			}
		}
	}
	else {
		browseButton.setFillColor(sf::Color(255, 120, 120, 255));
	}
	browseButton.setPosition(sf::Vector2f(50, 250));
	(*window).draw(browseButton);

	sf::Text browseText;
	browseText.setString("Browse for image...");
	browseText.setPosition(sf::Vector2f(55, 255));
	browseText.setCharacterSize(32);
	browseText.setColor(sf::Color(255, 255, 255, 255));
	browseText.setFont(loader.regular_font);
	(*window).draw(browseText);




	sf::RectangleShape nextButton;
	nextButton.setSize(sf::Vector2f(200, 40));
	if (mouseX > 700 && mouseX < 900 && mouseY > 700 && mouseY < 740) {
		nextButton.setFillColor(sf::Color(255, 150, 150, 255));
		if (mouseDown) {
			nextButton.setFillColor(sf::Color(120, 60, 60, 255));
			if (firstNameTextbox.containedText != "" && lastNameTextbox.containedText != "" && ageTextbox.containedText != "" && birthdayTextbox.containedText != "" && carepersonemailTextbox.containedText != "") {
				currPatient.createPatient(firstNameTextbox.containedText, lastNameTextbox.containedText, std::stoi(ageTextbox.containedText), birthdayTextbox.containedText, carepersonemailTextbox.containedText, levelofalzSlider.number);
				firstNameTextbox.containedText = "";
				lastNameTextbox.containedText = "";
				stage = "IMPORT_FAMILY";
			}
		}
	}
	else {
		nextButton.setFillColor(sf::Color(255, 120, 120, 255));
	}
	nextButton.setPosition(sf::Vector2f(700, 700));
	(*window).draw(nextButton);

	sf::Text nextText;
	nextText.setString("Add Another >");
	nextText.setPosition(sf::Vector2f(705, 700));
	nextText.setCharacterSize(32);
	nextText.setColor(sf::Color(255, 255, 255, 255));
	nextText.setFont(loader.regular_font);
	(*window).draw(nextText);


}