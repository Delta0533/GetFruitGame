#include "Game.h"


Game::Game(sf::RenderWindow &window) {

	//Wave
	for (int i = 0; i < 5; i++) {
		isWaveBuff[i] = false;
	}
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
	music.setVolume(10);
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
		enemy[i].Init(type, 5);
	}

	// Init Sound
	fruitCollectSoundBuffer.loadFromFile("Themesong/fruitCollect.mp3");
	fruitCollectSFX.setBuffer(fruitCollectSoundBuffer);
	fruitCollectSFX.setVolume(15);

	isGameOver = false;
	Loop(window);
}

void Game::Update(sf::Event& event, sf::RenderWindow& window)
{
	// Check if game is over || Comment to use God Mode so the game never over
	if (player.HP <= 0) isGameOver = true;  //GM mode

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			// push Esc to open menu
			if (event.key.code == sf::Keyboard::Escape) {
				mainMenu menu(window);
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
			enemy[i].Init(type, enemySpd);
		}
	}
	//wave 0
	if (player.score < 50) {
		enemySpd = 5;
		player.speed = 8;
		player.wave = 0;
	}
	//wave 1 
	else if (player.score >= 50 && player.score < 100 && isWaveBuff[0] == false) {
		player.HP += 15;
		player.wave = 1;
		enemySpd = 7;
		player.speed = 9;
		isWaveBuff[0] = true;
	}
	//wave 2 
	 else if (player.score >= 100 && player.score < 200 && isWaveBuff[1] == false) {
		player.HP += 20;
		player.wave = 2;
		enemySpd = 9;
		player.speed = 10;
		isWaveBuff[1] = true;
	}
	//wave 3 
	else if (player.score >= 200 && player.score < 300 && isWaveBuff[2] == false) {
		player.HP += 25;
		player.wave = 3;
		enemySpd = 10;
		player.speed = 11;
		isWaveBuff[2] = true;
	}
	//wave 4
	else if (player.score >= 300 && player.score < 400 && isWaveBuff[3] == false) {
		player.HP += 35;
		player.wave = 4;
		enemySpd = 12;
		player.speed = 13;
		isWaveBuff[3] = true;
	}
	//wave 5
	else if (player.score >= 400 && player.score < 500 && isWaveBuff[4] == false) {
		player.HP += 55;
		player.wave = 5;
		enemySpd = 15;
		player.speed = 15;
		isWaveBuff[4] = true;
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

	gui.Update(player.HP, player.score,player.wave);
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
	//window.close();
	Gameover gameover(window);
}
