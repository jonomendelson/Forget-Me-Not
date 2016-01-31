#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

class Loader {
public:
	sf::Texture logo_large_texture;
	sf::Texture logo_small_texture;

	sf::Font regular_font;
	sf::Font bold_font;

	sf::Sprite logo_large;

	sf::SoundBuffer starting_music_buffer;
	sf::Sound starting_music;

	


	int loadResources();
};

int Loader::loadResources() {
	if (!logo_large_texture.loadFromFile("logo_large.png")) { //load texture
		return -1;
	}
	if (!logo_small_texture.loadFromFile("logo_small.png")) {
		return -1;
	}
	if (!regular_font.loadFromFile("regular_font.ttf")) {
		return -1;
	}
	if (!bold_font.loadFromFile("bold_font.ttf")) {
		return -1;
	}
	if (!starting_music_buffer.loadFromFile("opening_music.wav")) {
		return -1;
	}
	else {
		starting_music.setBuffer(starting_music_buffer);
	}

	return 0;
}