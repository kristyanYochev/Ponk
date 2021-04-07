#include "MainGameScreen.h"
#include "Game.h"
#include "PlayerWinsScreen.h"
#include "SizePowerUp.h"
#include "SpeedPowerUp.h"
#include <random>

MainGameScreen::MainGameScreen(Game& game)
        :
        _game(game),
        _window(game.window()),
        _paddle1(50.f, 1000.f, sf::Vector2f(10.f, 100.f), game),
        _paddle2(
                game.screenSize().x - 50.f,
                1000.f,
                sf::Vector2f(10.f, 100.f),
                game,
                sf::Keyboard::Up,
                sf::Keyboard::Down
        ),
        _counter(game.font(), *this, 10),
        _ball(1000.f, *this),
        _randomEngine(std::random_device()())
{
    _powerUp = generatePowerUp();
}

std::unique_ptr<GameScreen> MainGameScreen::show()
{
    sf::Clock clk;

    const float updateTimestep = 1 / 120.f;
    float lag = 0;

    while (_window.isOpen() && _winningPlayer == -1)
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
            _powerUp->update();
            lag -= updateTimestep;
        }

        _window.clear();

        _paddle1.render(_window, lag);
        _paddle2.render(_window, lag);
        _ball.render(_window, lag);
        _powerUp->render(_window);
        _counter.render(_window);

        _window.display();
    }

    if (_winningPlayer != -1) return std::make_unique<PlayerWinsScreen>(_winningPlayer, _game);

    return {nullptr};
}

const sf::Vector2f& MainGameScreen::screenSize() const
{
    return _game.screenSize();
}

Paddle& MainGameScreen::paddle1()
{
    return _paddle1;
}

Paddle& MainGameScreen::paddle2()
{
    return _paddle2;
}

Ball& MainGameScreen::ball()
{
    return _ball;
}

void MainGameScreen::scoreForP1()
{
    _counter.scoreForP1();
    reset();
}

void MainGameScreen::scoreForP2()
{
    _counter.scoreForP2();
    reset();
}

void MainGameScreen::reset()
{
    _ball.reset();
    _paddle1.removeAppliedPowerUp();
    _paddle2.removeAppliedPowerUp();
    _powerUp = generatePowerUp();
}

void MainGameScreen::playerWon(unsigned int playerNumber)
{
    _winningPlayer = static_cast<int>(playerNumber);
}

std::unique_ptr<PowerUp> MainGameScreen::generatePowerUp()
{
    std::uniform_real_distribution<> distX(100.f, screenSize().x - 100.f);
    std::uniform_real_distribution<> distY(50, screenSize().y - 50.f);

    enum PowerUpType {
        SIZE = 0,
        SPEED = 1
    };

    std::uniform_int_distribution<> typeDist(0, 1);

    const int selectedType = typeDist(_randomEngine);

    switch (selectedType)
    {
    case SIZE:
        return std::make_unique<SizePowerUp>(
                _game.powerUpTexture(selectedType),
                sf::Vector2f(distX(_randomEngine), distY(_randomEngine)),
                *this
        );
    case SPEED:
        return std::make_unique<SpeedPowerUp>(
                _game.powerUpTexture(selectedType),
                sf::Vector2f(distX(_randomEngine), distY(_randomEngine)),
                *this
        );
    default:
        return nullptr; // unreachable
    }
}

void MainGameScreen::powerUpCollected()
{
    if (_ball.lastHitPaddle() == nullptr) return;

    _ball.lastHitPaddle()->applyPowerUp(std::move(_powerUp));

    _powerUp = generatePowerUp();
}
