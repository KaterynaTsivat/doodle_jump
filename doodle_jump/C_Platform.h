#pragma once
#include "pch.h"
#include "C_Doodle.h"
class C_Platform {
	struct Position_plat {
		int x_Plat;
		int y_Plat;
	};
	vector<Position_plat> vector_Plat;
	sf::Sprite* sprite_platform;
	sf::Texture texture_platform;
	int imgWidth;
	int score = 1;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font myFont;
	sf::Text myText;
	sf::Text scoreText;
public:
	C_Platform() {
		srand((time(nullptr)));

		texture_platform.loadFromFile("platform.png");
		sprite_platform = new sf::Sprite(texture_platform);

		imgWidth = sprite_platform->getTexture()->getSize().x;

		for (int i = 0; i < BAR_COUNT; ++i) {
			Position_plat c_position_plat;
			c_position_plat.x_Plat = rand() % WIDTH - imgWidth / 2;
			c_position_plat.y_Plat = rand() % HEIGHT;
			vector_Plat.push_back(c_position_plat);
		}

		vector_Plat[0].y_Plat = HEIGHT - 200;
	}


	// 
	void Draw(sf::RenderWindow& window) {
		for (int i = 0; i < BAR_COUNT; ++i) {
			sprite_platform->setPosition(vector_Plat[i].x_Plat, vector_Plat[i].y_Plat);
			window.draw(*sprite_platform);
		}
	}

	//
	bool Check_interactions(C_Doodle* pPlayer) {
		if (pPlayer == nullptr) return false;
		for (int i = 0; i < BAR_COUNT; ++i) {
			if (pPlayer->GetDy() > 0 && pPlayer->GetX() + pPlayer->GetWidth() > vector_Plat[i].x_Plat && pPlayer->GetX() < vector_Plat[i].x_Plat + imgWidth
				&& pPlayer->GetY() + pPlayer->GetHeight() + 55 > vector_Plat[i].y_Plat && pPlayer->GetY() + pPlayer->GetHeight() < vector_Plat[i].y_Plat + 1)
			{
				
				
				system("CLS");
				std::cout << " Doodle managed to jump " << score++ << " plates";
				pPlayer->Jump();
				return true;
			}
		}
		return false;
	}

	void emergence_platform(C_Doodle* pPlayer) {
		const int limit = HEIGHT / 3;
		if (pPlayer->GetY() < limit) {
			for (int i = 0; i < BAR_COUNT; ++i) {
				pPlayer->SetY(limit);
				vector_Plat[i].y_Plat -= (pPlayer->GetDy());
				if (vector_Plat[i].y_Plat > HEIGHT + 10) {
					vector_Plat[i].y_Plat = rand() % HEIGHT / 3 + 100;
					vector_Plat[i].x_Plat = rand() % WIDTH;
				}
			}
		}
	}

	/*void emergence_coin(C_Doodle* pPlayer) {
		const int limit = HEIGHT / 3;
		if (pPlayer->GetY() < limit) {
			for (int i = 0; i < COIN_COUNT; ++i) {
				pPlayer->SetY(limit);
				vector_Plat[i].y_Plat -= (pPlayer->GetDy());
				if (vector_Plat[i].y_Plat > HEIGHT + 10) {
					vector_Plat[i].y_Plat = rand() % HEIGHT / 3 + 100;
					vector_Plat[i].x_Plat = rand() % WIDTH;
				}
			}
		}
	}*/

	~C_Platform() { delete(sprite_platform); }
};