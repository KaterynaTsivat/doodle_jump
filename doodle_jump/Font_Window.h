//#pragma once
//#include "pch.h"
//class Font_Window : public sf::RenderWindow {
//	sf::Font myFont;
//	sf::Text myText;
//	// sf::Image _image;
//	sf::Texture texture;
//	sf::Sprite sprite;
//public:
//	Font_Window(int width, int heigth, std::string title) : sf::RenderWindow(sf::VideoMode(width, heigth), title.c_str()) {
//		if (!myFont.loadFromFile("arial.ttf")) {
//			throw;
//		}
//		myText.setFont(myFont);
//		myText.setString("Hello f!");
//		myText.setCharacterSize(40);
//		sf::Color color = sf::Color(50, 168, 62, 255);
//		myText.setFillColor(color);
//		myText.setPosition(100, 100);
//		sprite.setTexture(texture);
//		// myImage.setPosition(100, 100);
//		texture.create(20, 20);
//		myText.setStyle(sf::Text::Bold);
//	}
//
//	//shape.setFillColor(Color::Yellow);
//
//
//	void showWindow() {
//		while (this->isOpen())
//		{
//			sf::Event event;
//			while (this->pollEvent(event))
//			{
//				if (event.type == sf::Event::Closed) {
//					this->close();
//				}
//			}
//			this->clear(sf::Color(133, 220, 242, 255));
//			this->draw(myText);
//			texture.setRepeated(true);
//			texture.loadFromFile("background.jpg", sf::IntRect(1100, 1100, 11200, 1100));
//			sf::Sprite spite(texture);
//
//			this->draw(sprite);
//			this->display();
//		}
//	}
//};