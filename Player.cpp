#include "Player.h"

void Player::Init() {
	playerTexture.loadFromFile("Textures/Orange_Head_Walking-Sheet.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
	playerSprite.setPosition(585, 640);
	playerSprite.setScale(2.35f, 2.35f);

	// Init Player Status
	speed = 8;
	HP = 30;
	score = 0;
	playerFacing = 'a';
}

void Player::Update(sf::Event& event)
{
	// --- Walk Animation ---
	if (playerMovementAnimationClock.getElapsedTime().asMilliseconds() > 100) {
		currentAnimationFrame = (currentAnimationFrame + 1) % 3;
		playerMovementAnimationClock.restart();
	}
	// --- Walk Animation

	// Gravity
	if (playerSprite.getPosition().y < 640) playerSprite.move(0, 10);
	// Gravity

	// --- Player Movement ---
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerSprite.getPosition().x - speed > 0) { // Left
		playerFacing = 'a';
		playerSprite.setTextureRect(sf::IntRect(currentAnimationFrame * 32, 64, 32, 32));
		playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f(-speed, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerSprite.getPosition().x + speed < 1240) { // Right
		playerFacing = 'd';
		playerSprite.setTextureRect(sf::IntRect(currentAnimationFrame * 32, 96, 32, 32));
		playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f(speed, 0));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Mouse::isButtonPressed(sf::Mouse::Right)) && dashCD.getElapsedTime().asMilliseconds() > 250) {
		if (playerFacing == 'a' && playerSprite.getPosition().x - 150 > 0) {
			playerSprite.move(-150, 0); 
		}
		else if (playerFacing == 'd' && playerSprite.getPosition().x + 150 < 1240) {
			playerSprite.move(150, 0);
		}
		dashCD.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && JumpCD.getElapsedTime().asMilliseconds() > 500) {
		JumpCD.restart();
		playerSprite.move(0, -200);
	}
	// --- Player Movement ---
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}
