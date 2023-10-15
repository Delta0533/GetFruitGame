#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "mainMenu.h"
#include "Game.h"
#include <fstream>
#include <sstream>
#include <vector>

class Highscore
{
public:
	Highscore(sf::RenderWindow& window);
	void Update(sf::Event& event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window);

	struct HighScoreEntry {
		std::string playerName;
		int score;

		// Define a comparison operator for sorting
		bool operator<(const HighScoreEntry& other) const {
			return score > other.score; // Sort in descending order
		}
	};

	std::vector<HighScoreEntry> highScores;
	std::vector<HighScoreEntry> LoadHighScores(const std::string& filename);

	sf::Font font;
	sf::Texture bgTexture;
	sf::Sprite bg;

	sf::Text highScoreText[5];
};

