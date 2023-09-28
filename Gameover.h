#pragma once

#include "mainMenu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Gameover
{

public:
	Gameover(sf::RenderWindow& window);
	void Update(sf::Event& event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window);

	sf::Texture bgtexture;
	sf::Sprite bg;

};

