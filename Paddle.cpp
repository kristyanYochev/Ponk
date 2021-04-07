#include "Paddle.h"
#include "Game.h"
#include "PowerUp.h"

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
    float height = _sprite.getGlobalBounds().height;

    _position.y += _yVelocity * deltaTime;
    if (_position.y < 0) _position.y = 0;
    if (_position.y + height > _screenSize.y) _position.y = _screenSize.y - height;
}

void Paddle::render(sf::RenderWindow& window, float interpolationFactor)
{
    _sprite.setPosition(_position + sf::Vector2f(0, _yVelocity) * interpolationFactor);
    window.draw(_sprite);
}

sf::FloatRect Paddle::boundingRect() const
{
    return _sprite.getGlobalBounds();
}

void Paddle::scaleSpeed(float amount)
{
    _maxSpeed *= amount;
}

void Paddle::setHeightScale(float amount)
{
    _sprite.setScale(1, amount);
}

void Paddle::applyPowerUp(std::unique_ptr<PowerUp> powerUp)
{
    removeAppliedPowerUp();
    powerUp->applyTo(this);
    _appliedPowerUp = std::move(powerUp);
}

void Paddle::removeAppliedPowerUp()
{
    if (!_appliedPowerUp) return;

    _appliedPowerUp->removeFrom(this);
    _appliedPowerUp = nullptr;
}
