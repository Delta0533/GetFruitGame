#include"Game.h"
#include "mainMenu.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{
    srand(time(NULL));

    // --- Init Window ---
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fruits Slayer", sf::Style::Resize);
    window.setFramerateLimit(60);
    // --- Init Window ---

    mainMenu menu(window);

    return 0;
}
