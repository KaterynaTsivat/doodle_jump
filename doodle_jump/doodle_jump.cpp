#include "pch.h"
#include "C_Window.h"
#include "C_Doodle.h"
#include "C_Platform.h"
#include "Font_Window.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Doodle Game!");

	// для плавности движений
	window.setFramerateLimit(60);

	// 
	C_Doodle* c_doodle = new C_Doodle();
	C_Platform* c_platform = new C_Platform();
	C_Window* background = new C_Window();
	C_Window* font = new C_Window();
	/*Font_Window fw(1000, 700, "score++");
	fw.showWindow();
	sf::Font MyFont;
	sf::Text myText;
	myText.setString("score++");*/

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) { window.close(); }
		}
		//логика игры
		c_doodle->Move_Doodle();
		c_platform->emergence_platform(c_doodle);
		c_platform->Check_interactions(c_doodle);
		c_doodle->SetPosition();

		// отрисовка персонажей
		window.clear(sf::Color::White);

		background->Draw(window);
		c_doodle->Draw(window);
		c_platform->Draw(window);
		font->clear(sf::Color(133, 220, 242, 255));
		// font->Draw_Font(myText);
		window.display();
	}
	delete(c_platform);
	delete(c_doodle);
	delete(background);
}