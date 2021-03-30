#include "Ball.h"
#include "Common.h"
#include "Math.h"
#include <iostream>

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
    const sf::Vector2f size = sprite.getSize();
    currentPos += velocity * deltaTime;

    if (currentPos.y < 0 || currentPos.y + size.y > SCREEN_SIZE.y) velocity.y = -velocity.y;
    if (currentPos.x < 0 || currentPos.x + size.x > SCREEN_SIZE.x) velocity.x = -velocity.x;

    sprite.setPosition(currentPos);

    std::cout << velocity.x << ", " << velocity.y << std::endl;
}

void Ball::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
