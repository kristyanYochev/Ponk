#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::Font bitFont;
    bitFont.loadFromFile("Assets/Fonts/bit5x3.ttf");

    sf::Texture sizePowerUpTexture;
    sizePowerUpTexture.loadFromFile("Assets/Textures/SizePowerUp.png");

    sf::Texture speedPowerUpTexture;
    speedPowerUpTexture.loadFromFile("Assets/Textures/SpeedPowerUp.png");

    Game game(sf::Vector2f(800, 600), bitFont, { sizePowerUpTexture, speedPowerUpTexture });
    game.run();

    return 0;
}
