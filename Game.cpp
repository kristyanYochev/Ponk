#include "Game.h"
#include "GameScreen.h"
#include "MainGameScreen.h"

Game::Game(sf::Vector2f screenSize, sf::Font& font)
        :
        _screenSize(screenSize),
        _window(sf::VideoMode(screenSize.x, screenSize.y), "Ponk"),
        _currentScreen(std::make_unique<MainGameScreen>(*this)),
        _font(font)
{ }

void Game::run()
{
    while (_currentScreen && _window.isOpen())
    {
        _currentScreen = _currentScreen->show();
    }

    _window.close();
}

const sf::Vector2f& Game::screenSize() const
{
    return _screenSize;
}

sf::RenderWindow& Game::window()
{
    return _window;
}

sf::Font& Game::font()
{
    return _font;
}
