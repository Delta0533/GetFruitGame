#include "Highscore.h"

Highscore::Highscore(sf::RenderWindow& window)
{
	bgTexture.loadFromFile("Textures/Scoreboard.png");
	bg.setTexture(bgTexture);
	bg.setScale(0.65, 0.67);
    font.loadFromFile("Fonts/Wonderland.otf");

    std::vector<HighScoreEntry> highScores = LoadHighScores("highscores.yokung");

    for (int i = 0; i < highScores.size(); i++) {
        highScoreText[i].setFont(font);
        highScoreText[i].setFillColor(sf::Color::White);
        highScoreText[i].setCharacterSize(25);
        highScoreText[i].setPosition(770, 250 + (i * 60));
        highScoreText[i].setString(std::to_string(i+1) + " " + highScores[i].playerName + " " + std::to_string(highScores[i].score));
    }

	Loop(window);
}

void Highscore::Update(sf::Event& event, sf::RenderWindow& window)
{
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
}

void Highscore::Draw(sf::RenderWindow& window)
{
        window.draw(bg);
        for (int i = 0; i < 5; i++) {
            window.draw(highScoreText[i]);
        }
}

void Highscore::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(event, window);
		Draw(window);
		window.display();
	}
}

std::vector<Highscore::HighScoreEntry> Highscore::LoadHighScores(const std::string& filename)
{
    std::vector<Highscore::HighScoreEntry> highScores;
    // Open the file for reading
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Split the line into playerName and score
        std::istringstream iss(line);
        std::string playerName;
        int score;

        if (std::getline(iss, playerName, ',') && iss >> score) {
            highScores.push_back({ playerName, score });
        }
    }

    // Close the file
    file.close();

    // Sort the high scores in descending order
    std::sort(highScores.begin(), highScores.end());

    // Get the top five scores
    std::vector<Highscore::HighScoreEntry> topFive;
    if (highScores.size() >= 5) {
        topFive.assign(highScores.begin(), highScores.begin() + 5);
    }
    else {
        topFive = highScores;
    }

    return topFive;
}
