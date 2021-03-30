#include "Paddle.h"
#include "Common.h"

Paddle::Paddle(float xPos, float maxSpeed, const sf::Vector2f& size, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
        :
        maxSpeed(maxSpeed),
        sprite(size),
        yVelocity(0),
        upKey(upKey),
        downKey(downKey),
        position(xPos, 0.f)
{ }

void Paddle::handleInput()
{
    yVelocity = 0;
    yVelocity += sf::Keyboard::isKeyPressed(downKey) ? maxSpeed : 0;
    yVelocity += sf::Keyboard::isKeyPressed(upKey) ? -maxSpeed : 0;
}

void Paddle::update(float deltaTime)
{
    const sf::Vector2f& size = sprite.getSize();

    position.y += yVelocity * deltaTime;
    if (position.y < 0) position.y = 0;
    if (position.y + size.y > SCREEN_SIZE.y) position.y = SCREEN_SIZE.y - size.y;
}

void Paddle::render(sf::RenderWindow& window, float interpolationFactor)
{
    sprite.setPosition(position + sf::Vector2f(0, yVelocity) * interpolationFactor);
    window.draw(sprite);
}

sf::FloatRect Paddle::boundingRect() const
{
    return {position, sprite.getSize()};
}
