#include "Gameover.h"
#define playerNameLimit 12

Gameover::Gameover(sf::RenderWindow& window, int playerScore)
{
	bgtexture.loadFromFile("Textures/gameover.png");
	bg.setTexture(bgtexture);
	bg.setScale(0.67, 0.67);
	
	font.loadFromFile("Fonts/Wonderland.otf");
	playerNameText.setFont(font);
	playerNameText.setPosition(900, 480); // pos
	playerNameText.setFillColor(sf::Color::White);
	playerNameText.setCharacterSize(40);


	Loop(window, playerScore);
}

void Gameover::Update(sf::Event& event, sf::RenderWindow& window, int playerScore)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			// Escape
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Return) {
				saveScore(playerScore);
				mainMenu menu(window);
			}
		}

		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode == '\b' && playerName.size() != 0 && event.text.unicode != '\r') {
				playerName.erase(playerName.size() - 1, 1);
			}
			else if (playerName.size() < playerNameLimit && event.text.unicode != '\r' && ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') || (event.text.unicode >= 'a' && event.text.unicode <= 'z') || (event.text.unicode == ' '))) { // Max player's name len is 12
				playerName += event.text.unicode;
			}
		}
		playerNameText.setString(playerName);
	}
}

void Gameover::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(playerNameText);
}

void Gameover::Loop(sf::RenderWindow& window, int playerScore)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(event, window, playerScore);
		Draw(window);
		window.display();
	}
}

void Gameover::saveScore(int playerScore)
{
	// Handle score saving system
	std::string filename = "highscores.yokung";

	std::ofstream file(filename, std::ios::app);

	file << playerName << "," << playerScore << "\n";
	file.close();
}
