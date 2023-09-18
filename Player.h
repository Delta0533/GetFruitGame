#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Player
{
public:
	// --- Main Instance ---
	void Init();
	void Update(sf::Event& event);
	void Draw(sf::RenderWindow &window);
	// --- Main Instance ---

	// --- Clock ---
	

public:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// Player Status
	char playerFacing;
	int speed;
	int maxHP;
	int HP;
	int score;
	
	// Animation
	sf::Clock playerMovementAnimationClock;
	int currentAnimationFrame;

	// Dash
	sf::Clock dashCD;

	//Jump
	sf::Clock JumpCD;

};

