#include "Enemy.h"

void Enemy::Init(int enemyType)
{
	speedY = 6;
	speedX = 1;

	switch (enemyType) {
	case 0: {
		// Banana
		enemyTexture.loadFromFile("Textures/NewFruits.png");
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(120, 80, 20, 20));
		enemySprite.setScale(2.5, 2.5);
		points = 1;
		type = 0;
		break;
	}
	case 1: {
		// Cherry
		enemyTexture.loadFromFile("Textures/NewFruits.png");
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(280, 80, 20, 20));
		enemySprite.setScale(2.5, 2.5);
		points = 3;
		type = 1;
		break;
	}
	case 2: {
		// Thor
		enemyTexture.loadFromFile("Textures/NewFruits.png");
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(240, 0, 20, 20));
		enemySprite.setScale(2.5, 2.5);
		points = 5;
		type = 2;
		break;
	}
	case 3: {
		// Grape
		enemyTexture.loadFromFile("Textures/NewFruits.png");
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(60, 20, 20, 20));
		enemySprite.setScale(2.5, 2.5);
		points = 7;
		type = 3;
		break;
	}
	case 4: {
		// Golden Apple
		appleTexture.loadFromFile("Textures/NewFruits.png");
		appleSprite.setTexture(appleTexture);
		appleSprite.setTextureRect(sf::IntRect(40, 0, 20, 20));
		appleSprite.setScale(2.5, 2.5);
		points = 10;
		type = 4;
		break;
	}
	case 5: {
		// Bomb
		bombTexture.loadFromFile("Textures/bomby.png");
		bombSprite.setTexture(bombTexture);
		bombSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		bombSprite.setScale(2,2);
		type = 5;
		break;
	}
	default:
		//enemyTexture.loadFromFile("Textures/NewFruits.png"); //banana
		//enemySprite.setTexture(enemyTexture);
		//enemySprite.setTextureRect(sf::IntRect(140, 0, 20, 20));
		//enemySprite.setScale(2.5, 2.5);
		break;
	}

	int x = rand() % 1180;
	int y = rand() % 500;

	enemySprite.setPosition(x, 0 - y);
	bombSprite.setPosition(x, 0 - y);
	multiplier = 1.f;
	status = true;
}

void Enemy::Update(sf::Sprite playerSprite, int& playerScore, int& playerHP)
{
	// Move Down until hit ground
	if (enemySprite.getPosition().y < 720 || bombSprite.getPosition().y < 720) {
		enemySprite.move(0, speedY);
		bombSprite.move(0, speedY);
		bombSprite.move(speedX, 0);
	}
	else if (enemySprite.getPosition().y >= 720 || bombSprite.getPosition().y >= 720) {
		playerHP--;
		//std::cout << "HP = " << playerHP << " Score = " << playerScore << std::endl;
		status = false;
	}

	if (playerSprite.getGlobalBounds().intersects(enemySprite.getGlobalBounds()) || playerSprite.getGlobalBounds().intersects(bombSprite.getGlobalBounds())) {
		if (type != 5) {
			playerScore += points * multiplier;
			playerHP++;
		}
		//std::cout << "HP = " << playerHP << " Score = " << playerScore << std::endl;
		if (type == 5) playerHP -= 3;
		status = false;
	}
}

void Enemy::Draw(sf::RenderWindow& window)
{
	if (status) window.draw(enemySprite);
	if (status) window.draw(bombSprite);
}
