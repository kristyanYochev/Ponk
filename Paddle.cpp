#include "Paddle.h"
#include "Game.h"

Paddle::Paddle(
        float xPos,
        float maxSpeed,
        const sf::Vector2f& size,
        Game& game,
        sf::Keyboard::Key upKey,
        sf::Keyboard::Key downKey
)
        :
        _maxSpeed(maxSpeed),
        _sprite(size),
        _yVelocity(0),
        _upKey(upKey),
        _downKey(downKey),
        _position(xPos, 0.f),
        _screenSize(game.screenSize())
{ }

void Paddle::handleInput()
{
    _yVelocity = 0;
    _yVelocity += sf::Keyboard::isKeyPressed(_downKey) ? _maxSpeed : 0;
    _yVelocity += sf::Keyboard::isKeyPressed(_upKey) ? -_maxSpeed : 0;
}

void Paddle::update(float deltaTime)
{
    const sf::Vector2f& size = _sprite.getSize();

    _position.y += _yVelocity * deltaTime;
    if (_position.y < 0) _position.y = 0;
    if (_position.y + size.y > _screenSize.y) _position.y = _screenSize.y - size.y;
}

void Paddle::render(sf::RenderWindow& window, float interpolationFactor)
{
    _sprite.setPosition(_position + sf::Vector2f(0, _yVelocity) * interpolationFactor);
    window.draw(_sprite);
}

sf::FloatRect Paddle::boundingRect() const
{
    return {_position, _sprite.getSize()};
}
