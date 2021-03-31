#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::Font bitFont;
    bitFont.loadFromFile("Assets/Fonts/bit5x3.ttf");

    Game game(sf::Vector2f(800, 600), bitFont);
    game.run();

    return 0;
}
