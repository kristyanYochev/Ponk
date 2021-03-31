#include "Game.h"

Game::Game(sf::Vector2f screenSize, sf::Font& scoreCounterFont)
        :
        _screenSize(screenSize),
        _window(sf::VideoMode(screenSize.x, screenSize.y), "Ponk"),
        _paddle1(50.f, 1500.f, sf::Vector2f(10.f, 100.f), *this),
        _paddle2(
                screenSize.x - 50.f,
                2000.f,
                sf::Vector2f(10.f, 100.f),
                *this,
                sf::Keyboard::Up,
                sf::Keyboard::Down
        ),
        _counter(scoreCounterFont, *this, 10),
        _ball(1000.f, *this)
{ }

void Game::run()
{
    sf::Clock clk;

    const float updateTimestep = 1 / 120.f;
    float lag = 0;

    while (_window.isOpen())
    {
        lag += clk.getElapsedTime().asSeconds();
        clk.restart();

        sf::Event event{};
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) _window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) _ball.start();
        }

        _paddle1.handleInput();
        _paddle2.handleInput();

        while (lag >= updateTimestep)
        {
            _paddle1.update(updateTimestep);
            _paddle2.update(updateTimestep);
            _ball.update(updateTimestep);
            lag -= updateTimestep;
        }

        _window.clear();

        _paddle1.render(_window, lag);
        _paddle2.render(_window, lag);
        _ball.render(_window, lag);
        _counter.render(_window);

        _window.display();
    }
}

const sf::Vector2f& Game::screenSize() const
{
    return _screenSize;
}

const Paddle& Game::paddle1()
{
    return _paddle1;
}

const Paddle& Game::paddle2()
{
    return _paddle2;
}

void Game::scoreForP1()
{
    _counter.scoreForP1();
    _ball.reset();
}

void Game::scoreForP2()
{
    _counter.scoreForP2();
    _ball.reset();
}

void Game::playerWon(unsigned int playerNumber)
{
    _window.close();
}
