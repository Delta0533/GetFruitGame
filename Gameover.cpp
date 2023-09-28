#include "Gameover.h"

Gameover::Gameover(sf::RenderWindow& window)
{
	bgtexture.loadFromFile("Textures/gameover.png");
	bg.setTexture(bgtexture);
	bg.setScale(0.67, 0.67);
	

	Loop(window);
}

void Gameover::Update(sf::Event& event, sf::RenderWindow& window)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			// Escape
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Return) {
				mainMenu menu(window);
			}
		}
	}
}

void Gameover::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
}

void Gameover::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(event, window);
		Draw(window);
		window.display();
	}
}
