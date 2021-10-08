#pragma once
#include "pch.h"
class C_Window : public sf::RenderWindow {
	sf::Color _bgColor;

	sf::Texture texture_background;
	sf::Sprite * sprite_background;
	sf::IntRect IntRect;

	int window_width;
	int window_height;
public:

	// 
	C_Window() : RenderWindow (sf::VideoMode(window_width, window_height), "Doodle Game") {
		_bgColor = sf::Color::White;

		texture_background.loadFromFile("background.png");
		sprite_background = new sf::Sprite(texture_background);
	}

	// 
	void Draw(RenderWindow& windowBackground){ windowBackground.draw(*sprite_background); }

	// цвет
	void setBgColor(int r, int g, int b) {
		this->_bgColor.r = r;
		this->_bgColor.g = g;
		this->_bgColor.b = b;
	}
	void setBgColor(const sf::Color& _color) {
		this->_bgColor = sf::Color(_color);
	}
};