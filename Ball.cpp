#include "Ball.h"
#include "Math.h"
#include "Paddle.h"
#include "Game.h"

const double halfRootTwo = 0.7071067811865476;

Ball::Ball(float maxSpeed, Game& game, float size)
        :
        _maxSpeed(maxSpeed),
        _sprite(sf::Vector2f(size, size)),
        _velocity(0, 0),
        _position((game.screenSize() - _sprite.getSize()) / 2.f),
        _game(game)
{ }

void Ball::start()
{
    if (lengthSquared(_velocity) == 0)
    {
        _velocity = sf::Vector2f(_maxSpeed * halfRootTwo, _maxSpeed * halfRootTwo);
    }
}

void Ball::update(float deltaTime)
{
    _position += _velocity * deltaTime;

    handleScreenBorderCollision();

    handlePaddleCollision(_game.paddle1());
    handlePaddleCollision(_game.paddle2());
}

void Ball::handleScreenBorderCollision()
{
    const auto screenSize = _game.screenSize();
    const sf::Vector2f spriteSize = _sprite.getSize();

    if (_position.y < 0)
    {
        _velocity.y = -_velocity.y;
        _position.y = 0;
    }

    if (_position.y + spriteSize.y > screenSize.y)
    {
        _velocity.y = -_velocity.y;
        _position.y = screenSize.y - spriteSize.y;
    }

    if (_position.x < 0)
    {
        _velocity.x = -_velocity.x;
        _game.scoreForP2();
    }

    if (_position.x + spriteSize.x > screenSize.x)
    {
        _velocity.x = -_velocity.x;
        _game.scoreForP1();
    }
}

void Ball::render(sf::RenderWindow& window, float interpolationFactor)
{
    _sprite.setPosition(_position + _velocity * interpolationFactor);
    window.draw(_sprite);
}

bool Ball::collidesWith(const Paddle& paddle, sf::FloatRect& intersection) const
{
    return boundingRect().intersects(paddle.boundingRect(), intersection);
}

sf::FloatRect Ball::boundingRect() const
{
    return {_position, _sprite.getSize()};
}

void Ball::handlePaddleCollision(const Paddle& paddle)
{
    sf::FloatRect intersection;
    const float deflectionFactor = 1000.f;
    if (collidesWith(paddle, intersection))
    {
        const float collisionPointY = intersection.top;
        const float paddleCenterY = paddle.boundingRect().top + paddle.boundingRect().height / 2.f;

        _velocity.x = -_velocity.x;
        _velocity.y = ((collisionPointY - paddleCenterY) / paddle.boundingRect().height) * deflectionFactor;
        _position.x += sgn(_velocity.x) * intersection.width;
    }
}

void Ball::reset()
{
    _position = (_game.screenSize() - _sprite.getSize()) / 2.f;
    _velocity = sf::Vector2f(0, 0);
}
