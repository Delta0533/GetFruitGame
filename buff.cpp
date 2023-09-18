#include "buff.h"

void buff::Init(int buffType)
{
	switch (buffType) {
	case 0: { 
		// HP Buff
		buffTexture.loadFromFile("Textures/item_drop.png");
		buffSprite.setTexture(buffTexture);
		buffSprite.setTextureRect(sf::IntRect(0, 320, 32, 32));
		buffSprite.setScale(2, 2);
		type = 0;
		break;
	}
	case 1: {
		// Speed Buff
		buffTexture.loadFromFile("Textures/item_drop.png");
		buffSprite.setTexture(buffTexture);
		buffSprite.setTextureRect(sf::IntRect(0, 160, 32, 32));
		buffSprite.setScale(2, 2);
		type = 1;
		break;
	}
	case 2: {
		// Mystery Box
		buffTexture.loadFromFile("Textures/item_drop.png");
		buffSprite.setTexture(buffTexture);
		buffSprite.setTextureRect(sf::IntRect(0, 96, 32, 32));
		buffSprite.setScale(2, 2);
		type = 2;
		break;
	}
	default:
		break;
	}

	int x = rand() % 1220;
	int y = rand() % 500;

	//isSpeedBuff = false;
	//isSpeedDebuff = false;
	buffSprite.setPosition(x, 0 - y);
	status = true;
}

void buff::Update(int& playerHP, int& playerSpeed, sf::Sprite playerSprite, int &playerScore)
{
	if (animationClock.getElapsedTime().asSeconds() > 0.25f) {
		switch (type)
		{
		case 0: {
			currentAnimationFrame = (currentAnimationFrame + 1) % 8;
			animationClock.restart();
		}
		case 1: {
			currentAnimationFrame = (currentAnimationFrame + 1) % 4;
			animationClock.restart();
		}
		case 2: {
			currentAnimationFrame = (currentAnimationFrame + 1) % 6;
			animationClock.restart();
		}
		default:
			break;
		}

		animationClock.restart();
	}


	// Move Down until hit ground
	if (buffSprite.getPosition().y < 720) {
		switch (type) {
		case 0: {
			buffSprite.setTextureRect(sf::IntRect(currentAnimationFrame * 32, 320, 32, 32));
			break;
		}
		case 1: {
			buffSprite.setTextureRect(sf::IntRect(currentAnimationFrame * 32, 160, 32, 32));
			break;
		}
		case 2: {
			buffSprite.setTextureRect(sf::IntRect(currentAnimationFrame * 32, 96, 32, 32));
			break;
		}
		}
		buffSprite.move(0, 3.f);
	}
	else if (buffSprite.getPosition().y >= 720) {
		status = false;
	}

	// Check if Player hit Buff
	if (playerSprite.getGlobalBounds().intersects(buffSprite.getGlobalBounds())) {
		switch (type) {
		case 0: {
			// Heal
			playerHP += 5;
			status = false;
			break;
		}
		case 1: {
			// SPD
			isSpeedBuff = 1;
			status = false;
			speedBuffDuration.restart();
			break;
		}
		case 2: {
			int buffType = rand() % 2;
			if (buffType == 0) {
				std::cout << "Speed Debuff\n";
				isSpeedDebuff = 1;
				playerScore -= 10;
				speedDebuffDuration.restart();
				status = false;
				break;
			}
			else if (buffType == 1) {
				std::cout << "Score x2\n";
				isScoreBuff = 1;
				scoreBuffDuration.restart();
				status = false;
				break;
			}
			break;
		}
		}
	}

	
}

void buff::Draw(sf::RenderWindow& window)
{
	if (status) window.draw(buffSprite);
}

void buff::buffDurationUpdate(float& playerScoreMultiplier)
{
	scoreBuff(playerScoreMultiplier);
}

void buff::speedBuff(int& playerSpeed)
{
	if (isSpeedBuff == 1) {
		if (speedBuffDuration.getElapsedTime().asSeconds() < 5 && isSpeedBuff == 1) {
			playerSpeed = 15;
		}
		else if (isSpeedBuff == 1 && speedBuffDuration.getElapsedTime().asSeconds() >= 5) {
			playerSpeed = 8;
			std::cout << "Buff Duration Over\n";
			isSpeedBuff = 0;
		}
	}

	if (isSpeedDebuff == 1) {
		if (speedDebuffDuration.getElapsedTime().asSeconds() < 5 && isSpeedDebuff == 1) {
			playerSpeed = 4;
		}
		else if (isSpeedDebuff == 1 && speedDebuffDuration.getElapsedTime().asSeconds() >= 5) {
			playerSpeed = 8;
			std::cout << "Buff Duration Over\n";
			isSpeedDebuff = 0;
		}
	}
}

void buff::scoreBuff(float &multiplierBuff)
{
	if (isScoreBuff == 1) {
		if (scoreBuffDuration.getElapsedTime().asSeconds() > 5) {
			multiplierBuff = 1.f;
			isScoreBuff = 0;
		}
		else {
			multiplierBuff = 2.f;
		}
	}
	
}
