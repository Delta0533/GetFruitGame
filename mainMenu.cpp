#include "mainMenu.h"


mainMenu::mainMenu(sf::RenderWindow& window)
{
	//Background
	bgTexture.loadFromFile("Textures/fruitslayer.png");
	bg.setTexture(bgTexture);
	bg.setScale(0.65,0.67);

	//Play text
	font.loadFromFile("Fonts/Wonderland.otf");
	menuplay.setFont(font);
	menuplay.setFillColor(sf::Color::White);
	menuplay.setPosition(923,330);
	menuplay.setCharacterSize(48);
	menuplay.setString("play");

	//scoreboard
	menuscore.setFont(font);
	menuscore.setFillColor(sf::Color::White);
	menuscore.setPosition(840, 430);
	menuscore.setCharacterSize(48);
	menuscore.setString("scoreboard");

	//Exit text
	menunexit.setFont(font);
	menunexit.setFillColor(sf::Color::White);
	menunexit.setPosition(923,530);
	menunexit.setCharacterSize(48);
	menunexit.setString("exit");

	//---------- Loop ----------
	Loop(window);
}

void mainMenu::Update(sf::Event& event, sf::RenderWindow& window)
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
				Game game(window);
			}
		}
	}
}

void mainMenu::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(menuplay);
	window.draw(menunexit);
	window.draw(menuscore);
}

void mainMenu::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(event, window);
		Draw(window);
		window.display();
	}
}
