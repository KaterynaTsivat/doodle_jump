#pragma once
#include "pch.h"
class C_Doodle {
	int x, y;
	int imgWidth, imgHeight;
	float dy;
	sf::Sprite* sprite_doodle;
	sf::Sprite* sprite_platform;
	sf::Texture texture_doodle, texture_platform;
	bool jumpFlag;
	const sf::Sprite& GetImg() {
		if (jumpFlag) return *sprite_doodle;
		else return *sprite_platform;
	}

public:
	C_Doodle() : dy(0), jumpFlag(true) {
		x = /*static_cast<int>*/(WIDTH / 2);
		y = /*static_cast<int>*/(HEIGHT / 2);

		texture_doodle.loadFromFile("doodle.png");
		texture_platform.loadFromFile("platform.png");

		sprite_doodle = new sf::Sprite(texture_doodle);
		sprite_platform = new sf::Sprite(texture_platform);

		imgWidth = (sprite_platform->getTexture()->getSize().x);
		imgHeight = (sprite_platform->getTexture()->getSize().y);
	}

	void Draw(sf::RenderWindow& windoodle) { windoodle.draw(GetImg()); }

	void SetPosition() {
		sprite_platform->setPosition(x, y);
		sprite_doodle->setPosition(x, y);
	}

	float GetDy() { return dy; }
	int GetY()  { return y; }
	int GetX() { return x; }
	int GetWidth()  { return imgWidth; }
	int GetHeight() { return imgHeight; }
	void SetY(int _y) { y = _y; }

	void Jump() {
		// jumpFlag = false;
		dy = -10;
	}

	void Move_Doodle() {
		// перемещение дудла с помощью стрелок на клавиатуре
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   x += 4;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))    x -= 4;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))      y -= 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))    y += 8;

		// проверка что б дудл не вылетал влево из окна
		if (x <= 0)	x = 0;

		// чтобы дудл не вылетал вправо
		if (x >= WIDTH - imgWidth)	x = WIDTH - imgWidth;


	    jumpFlag = true;
		y += dy;
		dy += GRAVITY;

		// если дудл вылетает вниз
		if (y > HEIGHT - imgHeight) {
			// std::cout << "game is over"; return;
			// jumpFlag = false;
			// dy = -10;
		}
	}

	~C_Doodle() {
		delete(sprite_doodle);
		delete(sprite_platform);
	}
};