#ifndef PONK_MAINGAMESCREEN_H
#define PONK_MAINGAMESCREEN_H

#include <random>
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "Paddle.h"
#include "Ball.h"
#include "ScoreCounter.h"
#include "PowerUp.h"

class Game;

class MainGameScreen : public GameScreen
{
public:
    explicit MainGameScreen(Game& game);

    std::unique_ptr<GameScreen> show() override;

    const sf::Vector2f& screenSize() const;

    Paddle& paddle1();
    Paddle& paddle2();
    Ball& ball();

    void scoreForP1();
    void scoreForP2();

    void playerWon(unsigned playerNumber);

    void powerUpCollected();
private:
    std::unique_ptr<PowerUp> generatePowerUp();
    void reset();

    Game& _game;
    sf::RenderWindow& _window;
    Paddle _paddle1;
    Paddle _paddle2;
    Ball _ball;
    ScoreCounter _counter;
    std::unique_ptr<PowerUp> _powerUp;
    std::mt19937 _randomEngine;
    int _winningPlayer = -1;
};

#endif //PONK_MAINGAMESCREEN_H
