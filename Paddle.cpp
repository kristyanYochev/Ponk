#include "Paddle.h"

Paddle::Paddle(float xPos, float maxSpeed, const sf::Vector2f& size)
        :
        maxSpeed(maxSpeed),
        sprite(size),
        yVelocity(0)
{
    sprite.setPosition(xPos, 0.f);
}

void Paddle::handleInput()
{
    yVelocity = 0;
    yVelocity += sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? maxSpeed : 0;
    yVelocity += sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? -maxSpeed : 0;
}

void Paddle::update(float deltaTime)
{
    sprite.move(0, yVelocity * deltaTime);
}

void Paddle::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
