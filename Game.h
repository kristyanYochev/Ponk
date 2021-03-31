#ifndef PONK_GAME_H
#define PONK_GAME_H

#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "ScoreCounter.h"

class Game
{
public:
    Game(sf::Vector2f screenSize, sf::Font& scoreCounterFont);

    void run();
    const sf::Vector2f& screenSize() const;

private:
    sf::RenderWindow window;
    const sf::Vector2f _screenSize;
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;
    ScoreCounter counter;
};

#endif //PONK_GAME_H
