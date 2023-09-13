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


/*
	class that acts as the game engine.
	wrapper class.
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event event;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//TexturePlayer
	sf::Texture texture;
	sf::Sprite character;

	//TextureBackground
	sf::Texture BG1;
	sf::Sprite BackGround1;

	sf::Texture BG2;
	sf::Sprite BackGround2;

	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;
	float initialEnemySpeed;
	float speedIncrement;
	char facing;
	bool canDash;
	int timeDash;


	//Game objects
	std::vector<sf::Sprite> enemies;
	sf::Sprite enemy;
	sf::Texture enemytexture1;
	sf::Texture enemytexture2;
	sf::Texture enemytexture3;
	sf::Texture enemytexture4;
	sf::Texture enemytexture5;

	//Private Functions
	void initVariables();
	void initWindow();
	void initBG();
	void initEnemies();
	void initPlayer();
	void initFonts();
	void initText();


public:
	//Construstors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;
	

	//Functions
	void spawnEnemy();

	void pollEvent();
	void updateMousePostions();
	void updateCollision();
	void updateText();
	void updateEnemies();
	void updatePlayer();
	void update();

	void renderBG(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void renderPlayer(sf::RenderTarget& target);
	void render();
	
};

