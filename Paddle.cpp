#include "Paddle.h"
#include "Common.h"

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
    sf::Vector2f currentPos = sprite.getPosition();
    const sf::Vector2f& size = sprite.getSize();

    currentPos.y += yVelocity * deltaTime;
    if (currentPos.y < 0) currentPos.y = 0;
    if (currentPos.y + size.y > SCREEN_HEIGHT) currentPos.y = SCREEN_HEIGHT - size.y;

    sprite.setPosition(currentPos);
}

void Paddle::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
