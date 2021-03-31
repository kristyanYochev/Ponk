#include "Game.h"
#include "GameScreen.h"
#include "MainGameScreen.h"

Game::Game(sf::Vector2f screenSize, sf::Font& scoreCounterFont)
        :
        _screenSize(screenSize),
        _window(sf::VideoMode(screenSize.x, screenSize.y), "Ponk"),
        _currentScreen(std::make_unique<MainGameScreen>(*this, scoreCounterFont))
{ }

void Game::run()
{
    while (_currentScreen)
    {
        _currentScreen = _currentScreen->show();
    }
}

const sf::Vector2f& Game::screenSize() const
{
    return _screenSize;
}

sf::RenderWindow& Game::window()
{
    return _window;
}
