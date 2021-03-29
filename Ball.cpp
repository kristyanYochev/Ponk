#include "Ball.h"
#include "Common.h"
#include "Math.h"

const double halfRootTwo = 0.7071067811865476;

Ball::Ball(float maxSpeed, float size)
        :
        maxSpeed(maxSpeed),
        sprite(sf::Vector2f(size, size)),
        velocity(0, 0)
{
    sprite.setPosition((SCREEN_SIZE - sprite.getSize()) / 2.f);
}

void Ball::start()
{
    if (lengthSquared(velocity) == 0)
    {
        velocity = sf::Vector2f(maxSpeed * halfRootTwo, maxSpeed * halfRootTwo);
    }
}

void Ball::update(float deltaTime)
{
    sf::Vector2f currentPos = sprite.getPosition();
    currentPos += velocity * deltaTime;
    sprite.setPosition(currentPos);
}

void Ball::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
