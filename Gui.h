#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class gui
{
public:
	void Init();
	void Update(int playerHP, int playerScore);
	void Draw(sf::RenderWindow& window);

	sf::Font font;
	sf::Text hpText;
	sf::Text scoreText;
};

