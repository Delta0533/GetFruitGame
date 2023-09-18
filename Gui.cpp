#include "gui.h"

void gui::Init()
{
	font.loadFromFile("Fonts/Wonderland.otf");

	hpText.setFont(font);
	hpText.setFillColor(sf::Color::White);
	hpText.setPosition(0, 0);
	hpText.setCharacterSize(28);

	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(0, 40);
	scoreText.setCharacterSize(28);
}

void gui::Update(int playerHP, int playerScore)
{
	hpText.setString("HP = " + std::to_string(playerHP));
	scoreText.setString("Score = " + std::to_string(playerScore));
}

void gui::Draw(sf::RenderWindow& window)
{
	window.draw(hpText);
	window.draw(scoreText);
}
