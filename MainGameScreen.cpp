#include "MainGameScreen.h"
#include "Game.h"

MainGameScreen::MainGameScreen(Game& game, sf::Font& scoreCounterFont)
        :
        _game(game),
        _window(game.window()),
        _paddle1(50.f, 1500.f, sf::Vector2f(10.f, 100.f), game),
        _paddle2(
                game.screenSize().x - 50.f,
                2000.f,
                sf::Vector2f(10.f, 100.f),
                game,
                sf::Keyboard::Up,
                sf::Keyboard::Down
        ),
        _counter(scoreCounterFont, *this, 10),
        _ball(1000.f, *this)
{ }

std::unique_ptr<GameScreen> MainGameScreen::show()
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

    return {nullptr};
}

const sf::Vector2f& MainGameScreen::screenSize() const
{
    return _game.screenSize();
}

const Paddle& MainGameScreen::paddle1()
{
    return _paddle1;
}

const Paddle& MainGameScreen::paddle2()
{
    return _paddle2;
}

void MainGameScreen::scoreForP1()
{
    _counter.scoreForP1();
    _ball.reset();
}

void MainGameScreen::scoreForP2()
{
    _counter.scoreForP2();
    _ball.reset();
}

void MainGameScreen::playerWon(unsigned int playerNumber)
{
    _window.close();
}

