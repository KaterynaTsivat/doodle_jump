#pragma once
#include "pch.h"
class C_Window : public sf::RenderWindow {
	sf::Color _bgColor;

	sf::Texture texture_background;
	sf::Sprite * sprite_background;
	sf::IntRect IntRect;

	int window_width;
	int window_height;

	sf::Font myFont;
	sf::Text myText;
	sf::Sprite* sprite_font;
public:

	// 
	C_Window() : RenderWindow (sf::VideoMode(window_width, window_height), "Doodle Game") {
		_bgColor = sf::Color::White;

		texture_background.loadFromFile("background.png");
		sprite_background = new sf::Sprite(texture_background);

		if (!myFont.loadFromFile("arial.ttf")) {
			throw;
		}
		myText.setFont(myFont);
		myText.setString("score++");
		myText.setCharacterSize(40);
		sf::Color color = sf::Color(50, 168, 62, 255);
		myText.setFillColor(color);
		myText.setPosition(100, 100);
		// sprite.setTexture(texture);
		// myImage.setPosition(100, 100);
		// texture.create(20, 20);
		myText.setStyle(sf::Text::Bold);
	}

	void Draw_Font(RenderWindow& windowFont) { windowFont.draw(*sprite_font); }

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