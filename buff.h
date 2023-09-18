#pragma once
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class buff
{
public:
	void Init(int buffType);
	void Update(int &playerHP, int &playerSpeed, sf::Sprite playerSprite, int& playerScore);
	void Draw(sf::RenderWindow &window);

	void buffDurationUpdate(float& playerScoreMultiplier);

	sf::Texture buffTexture;
	sf::Sprite buffSprite;
	bool status;
	int type;

	int isSpeedBuff;
	int isSpeedDebuff;
	void speedBuff(int &playerSpeed);
	sf::Clock speedBuffDuration;
	sf::Clock speedDebuffDuration;

	int isScoreBuff;
	int scoreMultiplier;
	sf::Clock scoreBuffDuration;
	void scoreBuff(float &multiplierBuff);

	sf::Clock animationClock;
	int currentAnimationFrame;

};

