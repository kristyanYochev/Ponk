#ifndef PONK_MAINGAMESCREEN_H
#define PONK_MAINGAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "Paddle.h"
#include "Ball.h"
#include "ScoreCounter.h"

class Game;

class MainGameScreen : public GameScreen
{
public:
    explicit MainGameScreen(Game& game, sf::Font& scoreCounterFont);
    ~MainGameScreen() override = default;

    std::unique_ptr<GameScreen> show() override;

    const sf::Vector2f& screenSize() const;

    const Paddle& paddle1();
    const Paddle& paddle2();

    void scoreForP1();
    void scoreForP2();

    void playerWon(unsigned playerNumber);
private:
    Game& _game;
    sf::RenderWindow& _window;
    Paddle _paddle1;
    Paddle _paddle2;
    Ball _ball;
    ScoreCounter _counter;
};

#endif //PONK_MAINGAMESCREEN_H
