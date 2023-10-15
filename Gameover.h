#pragma once

#include "mainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <fstream>

class Gameover
{

public:
	Gameover(sf::RenderWindow& window, int playerScore);
	void Update(sf::Event& event, sf::RenderWindow& window, int playerScore);
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window, int playerScore);
	void saveScore(int playerScore);

	sf::Texture bgtexture;
	sf::Sprite bg;

	sf::Font font;
	std::string playerName;
	sf::Text playerNameText;


};

