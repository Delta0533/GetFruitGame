#include "Game.h"

Game::Game(sf::RenderWindow &window) {
	// Load Backgroud
	bg1Texture.loadFromFile("Textures/parallax-forest-back-trees.png");
	bg1Sprite.setTexture(bg1Texture);
	bg1Sprite.setTextureRect(sf::IntRect(0, 0, 272, 160));
	bg1Sprite.setScale(5.f, 4.5f);

	bg2Texture.loadFromFile("Textures/parallax-forest-front-trees.png");
	bg2Sprite.setTexture(bg2Texture);
	bg2Sprite.setTextureRect(sf::IntRect(0, 0, 272, 160));
	bg2Sprite.setScale(5.f, 4.5f);

	//Load Music
	music.openFromFile("Themesong/rebornsong.mp3");
	music.setLoop(true);
	music.setVolume(25);
	music.play();

	// Init Player
	player.Init();

	// Init GUI
	gui.Init();

	// Init Buff
	int buffType = rand() % 3;
	buff.Init(buffType);

	// Init Enemy
	for (int i = 0; i < maxEnemy; i++) {
		int type = rand() % 6;
		enemy[i].Init(type);
	}

	// Init Sound
	fruitCollectSoundBuffer.loadFromFile("Themesong/fruitCollect.mp3");
	fruitCollectSFX.setBuffer(fruitCollectSoundBuffer);
	fruitCollectSFX.setVolume(20);

	isGameOver = false;
	Loop(window);
}

void Game::Update(sf::Event& event, sf::RenderWindow& window)
{
	// Check if game is over || Comment to use God Mode so the game never over
	//if (player.HP <= 0) isGameOver = true;  //GM mode

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			// Escape
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}
	}

	player.Update(event);
	for (int i = 0; i < maxEnemy; i++) {
		if (enemy[i].status) {
			enemy[i].Update(player.playerSprite, player.score, player.HP);
			if (enemy[i].enemySprite.getGlobalBounds().intersects(player.playerSprite.getGlobalBounds()) && enemy[i].type != 5) {
				fruitCollectSFX.play();
			}
		}
		else {
			int type = rand() % 6;
			enemy[i].Init(type);
		}
	}

	if (buff.status) {
		buff.Update(player.HP, player.speed, player.playerSprite, player.score);
	}
	else {
		int buffType = rand() % 3;
		buff.Init(buffType);
	}

	for (int i = 0; i < maxEnemy; i++) {
		buff.buffDurationUpdate(enemy[i].multiplier);
	}

	buff.speedBuff(player.speed);

	gui.Update(player.HP, player.score);
}

void Game::Draw(sf::RenderWindow &window)
{
	window.draw(bg1Sprite);
	window.draw(bg2Sprite);

	player.Draw(window);
	for (int i = 0; i < maxEnemy; i++) {
		enemy[i].Draw(window);
	}

	buff.Draw(window);
	gui.Draw(window);
}

void Game::Loop(sf::RenderWindow &window)
{
	while (window.isOpen() && !isGameOver) {
		sf::Event event;
		window.clear();
		Update(event, window);
		Draw(window);
		window.display();
	}
	window.close();
}
