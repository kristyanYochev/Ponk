#include "Ball.h"
#include "Common.h"
#include "Math.h"
#include "Paddle.h"

const double halfRootTwo = 0.7071067811865476;

Ball::Ball(float maxSpeed, Paddle& paddle1, Paddle& paddle2, float size)
        :
        maxSpeed(maxSpeed),
        sprite(sf::Vector2f(size, size)),
        velocity(0, 0),
        position((SCREEN_SIZE - sprite.getSize()) / 2.f),
        paddle1(paddle1),
        paddle2(paddle2)
{ }

void Ball::start()
{
    if (lengthSquared(velocity) == 0)
    {
        velocity = sf::Vector2f(maxSpeed * halfRootTwo, maxSpeed * halfRootTwo);
    }
}

void Ball::update(float deltaTime)
{
    const sf::Vector2f size = sprite.getSize();
    position += velocity * deltaTime;

    if (position.y < 0 || position.y + size.y > SCREEN_SIZE.y) velocity.y = -velocity.y;
    if (position.x < 0 || position.x + size.x > SCREEN_SIZE.x) velocity.x = -velocity.x;

    handlePaddleCollision(paddle1);
    handlePaddleCollision(paddle2);
}

void Ball::render(sf::RenderWindow& window, float interpolationFactor)
{
    sprite.setPosition(position + velocity * interpolationFactor);
    window.draw(sprite);
}

bool Ball::collidesWith(const Paddle& paddle, sf::FloatRect& intersection) const
{
    return boundingRect().intersects(paddle.boundingRect(), intersection);
}

sf::FloatRect Ball::boundingRect() const
{
    return {position, sprite.getSize()};
}

void Ball::handlePaddleCollision(const Paddle& paddle)
{
    sf::FloatRect intersection;
    const float deflectionFactor = 1000.f;
    if (collidesWith(paddle, intersection))
    {
        const float collisionPointY = intersection.top;
        const float paddleCenterY = paddle.boundingRect().top + paddle.boundingRect().height / 2.f;

        velocity.x = -velocity.x;
        velocity.y = ((collisionPointY - paddleCenterY) / paddle.boundingRect().height) * deflectionFactor;
    }
}
