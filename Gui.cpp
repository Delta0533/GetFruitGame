#include "gui.h"

void gui::Init()
{
	font.loadFromFile("Fonts/Wonderland.otf");

	hpText.setFont(font);
	hpText.setFillColor(sf::Color::White);
	hpText.setPosition(10, 0);
	hpText.setCharacterSize(28);

	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10, 40);
	scoreText.setCharacterSize(28);

	waveText.setFont(font);
	waveText.setFillColor(sf::Color::White);
	waveText.setPosition(1140,0);
	waveText.setCharacterSize(28);
}

void gui::Update(int playerHP, int playerScore,int wave)
{
	hpText.setString("HP : " + std::to_string(playerHP));
	scoreText.setString("Score : " + std::to_string(playerScore));
	waveText.setString("Wave : " + std::to_string(wave));
}

void gui::Draw(sf::RenderWindow& window)
{
	window.draw(hpText);
	window.draw(scoreText);
	window.draw(waveText);
}
