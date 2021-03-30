#include "Ball.h"
#include "Common.h"
#include "Math.h"

const double halfRootTwo = 0.7071067811865476;

Ball::Ball(float maxSpeed, float size)
        :
        maxSpeed(maxSpeed),
        sprite(sf::Vector2f(size, size)),
        velocity(0, 0),
        position((SCREEN_SIZE - sprite.getSize()) / 2.f)
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
}

void Ball::render(sf::RenderWindow& window, float interpolationFactor)
{
    sprite.setPosition(position + velocity * interpolationFactor);
    window.draw(sprite);
}
