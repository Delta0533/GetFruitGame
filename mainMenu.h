#pragma once

#include "game.h"
#include "Highscore.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class mainMenu
{
public:
	mainMenu(sf::RenderWindow& window);
	void Update(sf::Event& event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window);

	sf::Texture bgTexture;
	sf::Sprite bg;

	sf::Font font;
	sf::Text menuplay;
	sf::Text menunexit;
	sf::Text menuscore;

	sf::Text nametext;

	int here; 
};
