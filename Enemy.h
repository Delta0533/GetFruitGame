#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

class Enemy
{
public:
	// --- Main Instance ---
	void Init(int enemyType);
	void Update(sf::Sprite playerSprite, int& playerScore, int& playerHP);
	void Draw(sf::RenderWindow& window);
	// --- Main Instane ---

	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::Texture appleTexture;
	sf::Sprite appleSprite;
	sf::Texture bombTexture;
	sf::Sprite bombSprite;
	int type;
	bool status;
	int points;
	int speedY;
	int speedX;

	float multiplier;
};

