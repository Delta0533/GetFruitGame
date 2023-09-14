#include "Game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	//game logic
	this->endGame = false;
	this->points = 0;
	this->health = 30;
	this->enemySpawnTimerMax = 14.0f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
	this->skillSpwanTimerMax = 200.0f;
	this->skillSpawnTimer = this->skillSpwanTimerMax;
	this->maxSkill = 10;
	this->mouseHeld = false;
	this->facing = 'a';
	this->canDash = false;
	this->timeDash = 0;

}


void Game::initWindow()
{
	this->VideoMode.height = 720;
	this->VideoMode.width = 1280;

	this->window = new sf::RenderWindow(this->VideoMode, "Oyasuminasai!", sf::Style::Close | sf::Style::Resize);

	this->window->setFramerateLimit(60);
}


void Game::initBG()
{
	this->BG1.loadFromFile("Textures/parallax-forest-back-trees.png");
	this->BackGround1.setTexture(BG1);
	this->BackGround1.setTextureRect(sf::IntRect(0, 0, 272, 160));
	this->BackGround1.setScale(sf::Vector2f(5, 4.5));

	this->BG2.loadFromFile("Textures/parallax-forest-front-trees.png");
	this->BackGround2.setTexture(BG2);
	this->BackGround2.setTextureRect(sf::IntRect(0, 0, 272, 160));
	this->BackGround2.setScale(sf::Vector2f(5, 4.5));
}


void Game::initFonts()
{
	this->font.loadFromFile("Fonts/Wonderland.otf");
}


void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(26);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setPosition(10, 0);
	this->uiText.setString("NONE");
}


void Game::initSkill()
{
	this->skil.setPosition(10.f, 10.f);
}


void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);

}


void Game::initPlayer()
{
	this->texture.loadFromFile("Textures/Orange_Head_Walking-Sheet.png");
	this->character.setTexture(texture);  //ต้องเอารูปไปใส่ในกล่องก่อน
	this->character.setTextureRect(sf::IntRect(0, 64, 32, 32)); //x,y,w,h เกี่ยวกับ animation
	this->character.setPosition(sf::Vector2f(585, 640));  //ตำแหน่งจุดเกิดของ character 
	this->character.setScale(sf::Vector2f(2.35, 2.35));   //ปรับขนาด character
}


//Constructors / Destructors  อย่าลืมเรียกฟังชันเวลาเพิ่มอะไรเข้ามา!!!
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initBG();
	this->initFonts();
	this->initText();
	this->initEnemies();
	this->initPlayer();
	this->initSkill();

}


Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}


//Functions
void Game::spawnSkill()
{
	this->skil.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->skil.getPosition().x)), 0.f);

	//Randomize skill types
	int type = rand() % 3;

	switch (type)
	{
	case 0:
		this->skill1.loadFromFile("Textures/Healitem.png"); 
		this->skil.setTexture(skill1);
		this->skil.setTextureRect(sf::IntRect(0, 0, 32, 32));
		this->skil.setScale(2.5, 2.5);
		break;
	case 1:
		this->skill2.loadFromFile("Textures/buffitem.png");
		this->skil.setTexture(skill2);
		this->skil.setTextureRect(sf::IntRect(0, 0, 32, 32));
		this->skil.setScale(2.5, 2.5);
		break;
	/*case 2:
		this->skill3.loadFromFile("Textures/Bigitem.png");
		this->skil.setTexture(skill3);
		this->skil.setTextureRect(sf::IntRect(0, 0, 32, 32));
		this->skil.setScale(2.5, 2.5);
		break;*/
	default:
		this->skill1.loadFromFile("Textures/Healitem.png");
		this->skil.setTexture(skill1);
		this->skil.setTextureRect(sf::IntRect(0, 0, 32, 32));
		this->skil.setScale(2.5, 2.5);
		break;
	}

	//spawn the enemy
	this->Skills.push_back(this->skil);
}


void Game::spawnEnemy()
{
	/*
	return void

	spawn enemies and set their types and color and spawn them position randomly
	-set a random position
	-set a random color
	-add enemy to the vector
	*/
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getPosition().x)), 0.f);
		

	//Randomize enemy types
	int type = rand() % 6;

	switch (type)
	{
	case 0:
		this->enemytexture1.loadFromFile("Textures/NewFruits.png"); //Banana
		this->enemy.setTexture(enemytexture1);
		this->enemy.setTextureRect(sf::IntRect(140, 0, 20, 20));
		this->enemy.setScale(2.5, 2.5);
		break;
	case 1:
		this->enemytexture2.loadFromFile("Textures/NewFruits.png");  //Cherry
		this->enemy.setTexture(enemytexture2);
		this->enemy.setTextureRect(sf::IntRect(280, 80, 20, 20));
		this->enemy.setScale(2.5, 2.5);
		break;
	case 2:
		this->enemytexture3.loadFromFile("Textures/NewFruits.png");   //Grape
		this->enemy.setTexture(enemytexture3);
		this->enemy.setTextureRect(sf::IntRect(60, 0, 20, 20));
		this->enemy.setScale(2.5, 2.5);
		break;
	case 3:
		this->enemytexture4.loadFromFile("Textures/NewFruits.png");   //Thor
		this->enemy.setTexture(enemytexture4);
		this->enemy.setTextureRect(sf::IntRect(240, 20, 20, 20));
		this->enemy.setScale(2.5, 2.5);
		break;
	case 4:
		this->enemytexture5.loadFromFile("Textures/NewFruits.png");  //Goldenapple
		this->enemy.setTexture(enemytexture5);
		this->enemy.setTextureRect(sf::IntRect(40, 0, 20, 20));
		this->enemy.setScale(2.5, 2.5);
		break;
	case 5:
		this->enenmybomber.loadFromFile("Textures/bomby.png");  //bomber
		this->enemy.setTexture(enenmybomber);
		this->enemy.setTextureRect(sf::IntRect(0, 0, 64, 64));
		this->enemy.setScale(2.0, 2.0);
		break;
	default:
		this->enemytexture1.loadFromFile("Textures/NewFruits.png");
		this->enemy.setTexture(enemytexture1);
		this->enemy.setTextureRect(sf::IntRect(140, 0, 20, 20));
		this->enemy.setScale(2.5, 2.5);
		break;
	}


	//spawn the enemy
	this->enemies.push_back(this->enemy);
}


void Game::pollEvent()
{
	//Event event;
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}


void Game::updateMousePostions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}

void Game::updateCollision()
{
	// Get the global bounds of the player character
	sf::FloatRect playerBounds = character.getGlobalBounds();

	// Iterate through the enemies
	for (size_t i = 0; i < enemies.size(); i++)
	{
		// Get the global bounds of the current enemy
		sf::FloatRect enemyBounds = enemies[i].getGlobalBounds();

		// Check for collision between the player and the current enemy
		if (playerBounds.intersects(enemyBounds))
		{
			// Handle collision (e.g., reduce player's health, remove enemy, etc.)
			health--; // Example: Decrease player's health when a collision occurs
			std::cout << "Collision detected! Health: " << health << std::endl;

			// Remove the enemy
			enemies.erase(enemies.begin() + i);
		}
	}
}


void Game::updateSkillCollision()
{
	sf::FloatRect playerBounds = character.getGlobalBounds();

	for (size_t i = 0; i < Skills.size(); i++)
	{
		sf::FloatRect skillBounds = Skills[i].getGlobalBounds();

		if (playerBounds.intersects(skillBounds))
		{
			//health--; 
			std::cout << "Collision detected! Health: " << health << std::endl;

			Skills.erase(Skills.begin() + i);
		}
	}
}


void Game::updateText()
{
	std::stringstream ss;

	ss << "Health: " << this->health << "\n"
		<< "Points: " << this->points << "\n";

	this->uiText.setString(ss.str());
}


void Game::updateSkill()
{
	if (this->Skills.size() < this->maxSkill)
	{
		if (this->skillSpawnTimer >= this->skillSpwanTimerMax)
		{
			// Spawn the enemy and reset timer
			this->spawnSkill();
			this->skillSpawnTimer = 0.f;
		}
		else
			this->skillSpawnTimer += 1.f;
	}
	float initialSkillSpeed = 3.0f; // Adjust value 

	float skillSpeed = initialSkillSpeed;

	// Move and update enemies
	for (int i = 0; i < this->Skills.size(); i++) {
		bool deleted = false;

		// Move enemies using the current enemySpeed
		this->Skills[i].move(0.f, skillSpeed += 0.5);

		if (this->Skills[i].getPosition().y > this->window->getSize().y)
		{
			this->Skills.erase(this->Skills.begin() + i);
		}

		// Check for collision with the player character
		if (this->character.getGlobalBounds().intersects(this->Skills[i].getGlobalBounds()))
		{
			// Gain points based on the enemy type
			if (this->Skills[i].getTexture() == &this->skill1)   // heal 5
				this->health += 5;
			else if (this->Skills[i].getTexture() == &this->skill2)   //คิดไม่อกก
				this->points += 0;
			//else if (this->Skills[i].getTexture() == &this->skill3)   //ขยายร่าง 
			//	this->points += 0;

			// Delete the enemy
			deleted = true;
			this->Skills.erase(this->Skills.begin() + i);
		}

		// If a collision occurred, break the loop to avoid double counting
		if (deleted)
			break;
	}
}


void Game::updateEnemies()
{
	// Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			// Spawn the enemy and reset timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}
	float initialEnemySpeed = 5.0f; // Adjust value 
	float speedIncrement = 1.0f;    // Adjust value 

	float enemySpeed = initialEnemySpeed;

	// Move and update enemies
	for (int i = 0; i < this->enemies.size(); i++) {
		bool deleted = false;

		// Move enemies using the current enemySpeed
		this->enemies[i].move(0.f, enemySpeed+=0.5);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;   //ปรับเสียเลือด
			std::cout << "health: " << this->health << "\n";
		}

		// Check for collision with the player character
		if (this->character.getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
		{
			// if collision occur Increase health by 1  
			this->health += 1;   

			// Gain points based on the enemy type
			if (this->enemies[i].getTexture() == &this->enemytexture1)
				this->points += 1;
			else if (this->enemies[i].getTexture() == &this->enemytexture2)
				this->points += 3;
			else if (this->enemies[i].getTexture() == &this->enemytexture3)
				this->points += 5;
			else if (this->enemies[i].getTexture() == &this->enemytexture4)
				this->points += 7;
			else if (this->enemies[i].getTexture() == &this->enemytexture5)
				this->points += 10;
			else if (this->enemies[i].getTexture() == &this->enenmybomber)
				this->health -= 2;

			// Delete the enemy
			deleted = true;
			this->enemies.erase(this->enemies.begin() + i);
		}

		// Gradually increase enemySpeed
		enemySpeed *= speedIncrement;

		// If a collision occurred, break the loop to avoid double counting
		if (deleted)
			break;
	}
}


void Game::updatePlayer()
{
	sf::Vector2f currentPosition = character.getPosition();
	sf::Vector2f playerPosition = character.getPosition();

	if (timeDash < 30) timeDash++;
	else if (timeDash >= 30) canDash = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && character.getPosition().x > 0)
	{
		int xTexture = 0;
		xTexture = (int)character.getPosition().x / 30 % 4; //ปรับตรงเลข 30 ได้ คือความsmooth ของ animation
		xTexture = xTexture * 32;

		character.setTextureRect(sf::IntRect(xTexture, 64, 32, 32)); //x,y,w,h
		character.move(-8.f, 0.f);
		facing = 'a';
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && character.getPosition().x < window->getSize().x - 50)
	{
		int xTexture = 0;
		xTexture = (int)character.getPosition().x / 30 % 4;
		xTexture = xTexture * 32;

		character.setTextureRect(sf::IntRect(xTexture, 96, 32, 32)); //x,y,w,h
		character.move(8.f, 0.f);
		facing = 'd';
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && canDash && character.getPosition().x - 150 > 0 && character.getPosition().x + 200 < window->getSize().x) {
		switch (facing)
		{
		case 'a': character.setPosition(currentPosition + sf::Vector2f(-150, 0)); timeDash = 0; canDash = false; break;
		case 'd': character.setPosition(currentPosition + sf::Vector2f(150, 0)); timeDash = 0; canDash = false; break;
		default:
			break;
		}
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	int xTexture = 0;
	//	xTexture = (int)character.getPosition().y / 30 % 4; //อย่าลืมแก้ getPositionเปนแกน y
	//	xTexture = xTexture * 32;

	//	character.setTextureRect(sf::IntRect(xTexture, 0, 32, 32)); //x,y,w,h
	//	character.move(0.f, -1.f);   //แก้ความเร็วในแกน y ด้วย
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	int xTexture = 0;
	//	xTexture = (int)character.getPosition().y / 30 % 4;
	//	xTexture = xTexture * 32;

	//	character.setTextureRect(sf::IntRect(xTexture, 32, 32, 32)); //x,y,w,h
	//	character.move(0.f, 1.f);
	//}
}


void Game::update()
{
	this->pollEvent();

	if (this->endGame == false)
	{
		this->updateMousePostions();

		this->updateText();

		this->updateEnemies();

		this->updateSkill();

		this->updatePlayer();

		this->updateCollision();

		this->updateSkillCollision();

	}

	//Endgame condition
	if (this->health <= 0)
		this->endGame = true;
}


void Game::renderBG(sf::RenderTarget& target)
{
	target.draw(this->BackGround1);
	target.draw(this->BackGround2);
}


void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}


void Game::renderEnemies(sf::RenderTarget& target)
{
	//rendering all enemy
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}


void Game::renderSkill(sf::RenderTarget& target)
{
	for (auto& r : this->Skills)
	{
		target.draw(r);
	}
}

void Game::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->character);
}


void Game::render()
{
	this->window->clear();

	//Draw game object
	this->renderBG(*this->window);

	this->renderEnemies(*this->window);

	this->renderSkill(*this->window);

	this->renderText(*this->window);

	this->renderPlayer(*this->window);

	this->window->display();
}


