#include "mainMenu.h"


mainMenu::mainMenu(sf::RenderWindow& window)
{
	//Background
	bgTexture.loadFromFile("Textures/fruitslayer.png");
	bg.setTexture(bgTexture);
	bg.setScale(0.65, 0.67);

	here = 1;
	//Play text
	font.loadFromFile("Fonts/Wonderland.otf");
	menuplay.setFont(font);
	menuplay.setFillColor(sf::Color::Red);
	menuplay.setPosition(923, 330);
	menuplay.setCharacterSize(48);
	menuplay.setString("play"); //here =  1

	//scoreboard
	menuscore.setFont(font);
	menuscore.setFillColor(sf::Color::White);
	menuscore.setPosition(840, 430);
	menuscore.setCharacterSize(48);
	menuscore.setString("scoreboard"); //here = 2

	//Exit text
	menunexit.setFont(font);
	menunexit.setFillColor(sf::Color::White);
	menunexit.setPosition(923, 530);
	menunexit.setCharacterSize(48);
	menunexit.setString("exit"); // here = 3

	//Myname text
	nametext.setFont(font);
	nametext.setFillColor(sf::Color::White);
	nametext.setPosition(0,680);
	nametext.setCharacterSize(24);
	nametext.setString("66010533 Prompipat Thongtub");
	
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
			if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space) {
				if (here == 1)Game game(window);//play
				else if (here == 2)Highscore highscore(window);  //score board 
				else if (here == 3) window.close();;//exit
			}
			if (event.key.code == sf::Keyboard::Up && here != 1 || event.key.code == sf::Keyboard::W && here != 1) {
				here--;
			}
			if (event.key.code == sf::Keyboard::Down && here != 3 || event.key.code == sf::Keyboard::S && here != 3) {
				here++;
			}
		}
		if (here == 1) { // play on 
			menuplay.setFillColor(sf::Color::Red);
			menuscore.setFillColor(sf::Color::White);
			menunexit.setFillColor(sf::Color::White);
		}
		if (here == 2) {//  score on
			menuplay.setFillColor(sf::Color::White);
			menuscore.setFillColor(sf::Color::Red);
			menunexit.setFillColor(sf::Color::White);
		}
		if (here == 3) {// exit on
			menuplay.setFillColor(sf::Color::White);
			menuscore.setFillColor(sf::Color::White);
			menunexit.setFillColor(sf::Color::Red);
		}
	}
}

void mainMenu::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(menuplay);
	window.draw(menunexit);
	window.draw(menuscore);
	window.draw(nametext);
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
