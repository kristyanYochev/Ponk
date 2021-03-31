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

    const Paddle& paddle1();
    const Paddle& paddle2();

    void scoreForP1();
    void scoreForP2();

    void playerWon(unsigned playerNumber);
private:
    sf::RenderWindow _window;
    const sf::Vector2f _screenSize;
    Paddle _paddle1;
    Paddle _paddle2;
    Ball _ball;
    ScoreCounter _counter;
};

#endif //PONK_GAME_H
