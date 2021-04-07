#include "PowerUp.h"
#include "MainGameScreen.h"
#include "Ball.h"

PowerUp::PowerUp(sf::Texture& texture, const sf::Vector2f& position, MainGameScreen& mainGameScreen, float size)
        :
        _sprite(texture),
        _mainGameScreen(mainGameScreen)
{
    _sprite.setPosition(position);
    _sprite.setScale(size, size);
}

void PowerUp::render(sf::RenderWindow& window)
{
    window.draw(_sprite);
}

void PowerUp::update()
{
    Ball& ball = _mainGameScreen.ball();
    sf::FloatRect boundingBox = _sprite.getGlobalBounds();

    if (ball.boundingRect().intersects(boundingBox))
    {
        _mainGameScreen.powerUpCollected();
    }
}


