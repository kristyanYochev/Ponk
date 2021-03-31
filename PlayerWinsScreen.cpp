#include "PlayerWinsScreen.h"
#include "MainGameScreen.h"
#include "Game.h"

PlayerWinsScreen::PlayerWinsScreen(unsigned int playerNumber, Game& game)
        :
        _text("Player " + std::to_string(playerNumber) + " wins!", game.font()),
        _window(game.window()),
        _game(game)
{
    sf::FloatRect boundingBox = _text.getLocalBounds();
    _text.setScale(2.f, 2.f);
    _text.setOrigin(boundingBox.width / 2.f, boundingBox.height / 2.f);
    _text.setPosition(game.screenSize() / 2.f);
}

std::unique_ptr<GameScreen> PlayerWinsScreen::show()
{
    bool quit = false;
    while (!quit && _window.isOpen())
    {
        sf::Event event{};
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) _window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) quit = true;
        }

        _window.clear();
        _window.draw(_text);
        _window.display();
    }

    return std::make_unique<MainGameScreen>(_game);
}