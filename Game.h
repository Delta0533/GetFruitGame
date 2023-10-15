#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "gui.h"
#include "buff.h"
#include "mainMenu.h"
#include "Gameover.h"

#define maxEnemy 15
#define maxbomb 5

class Game {
public:
	// --- Main Instance ---
	Game(sf::RenderWindow& window);

	void Update(sf::Event& event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window);

	bool isGameOver;
	// --- Main Instance ---

public:
	// Background
	sf::Texture bg1Texture;
	sf::Sprite bg1Sprite;
	sf::Texture bg2Texture;
	sf::Sprite bg2Sprite;


	// Player
	Player player;

	// Enemy
	Enemy enemy[maxEnemy];
	Enemy bomb[maxbomb];
	int enemySpd;

	// Buff
	buff buff;

	// GUI
	gui gui;

	//Wave
	bool isWaveBuff[5];

	//Themesong
	sf::Music music;

	// Sound
	sf::SoundBuffer fruitCollectSoundBuffer;
	sf::Sound fruitCollectSFX;

	
};
