#include "Ball.h"
#include "Common.h"
#include "Math.h"
#include "Paddle.h"
#include "ScoreCounter.h"

const double halfRootTwo = 0.7071067811865476;

Ball::Ball(float maxSpeed, Paddle& paddle1, Paddle& paddle2, ScoreCounter& counter, float size)
        :
        maxSpeed(maxSpeed),
        sprite(sf::Vector2f(size, size)),
        velocity(0, 0),
        position((SCREEN_SIZE - sprite.getSize()) / 2.f),
        paddle1(paddle1),
        paddle2(paddle2),
        counter(counter)
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
    position += velocity * deltaTime;

    handleScreenBorderCollision();

    handlePaddleCollision(paddle1);
    handlePaddleCollision(paddle2);
}

void Ball::handleScreenBorderCollision()
{
    const sf::Vector2f size = sprite.getSize();
    if (position.y < 0)
    {
        velocity.y = -velocity.y;
        position.y = 0;
    }

    if (position.y + size.y > SCREEN_SIZE.y)
    {
        velocity.y = -velocity.y;
        position.y = SCREEN_SIZE.y - size.y;
    }

    if (position.x < 0)
    {
        velocity.x = -velocity.x;
        reset();
        counter.scoreForP2();
    }

    if (position.x + size.x > SCREEN_SIZE.x)
    {
        velocity.x = -velocity.x;
        reset();
        counter.scoreForP1();
    }
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

void Ball::reset()
{
    position = (SCREEN_SIZE - sprite.getSize()) / 2.f;
    velocity = sf::Vector2f(0, 0);
}
