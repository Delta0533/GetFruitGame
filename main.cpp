#include"Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{
    srand(time(NULL));

    // --- Init Window ---
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fruits Slayer", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    // --- Init Window ---

    Game game(window);

    return 0;
}
