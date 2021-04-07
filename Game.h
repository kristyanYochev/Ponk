#ifndef PONK_GAME_H
#define PONK_GAME_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "ScoreCounter.h"
#include "GameScreen.h"

class Game
{
public:
    Game(sf::Vector2f screenSize, sf::Font& font, std::vector<sf::Texture> powerUpTextures);

    void run();
    const sf::Vector2f& screenSize() const;
    sf::Font& font();

    sf::Texture& powerUpTexture(int powerUpType);

    sf::RenderWindow& window();
private:
    sf::RenderWindow _window;
    sf::Font& _font;
    std::vector<sf::Texture> _powerUpTextures;
    const sf::Vector2f _screenSize;
    std::unique_ptr<GameScreen> _currentScreen;
};

#endif //PONK_GAME_H
