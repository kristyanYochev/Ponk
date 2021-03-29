#ifndef PONK_PADDLE_H
#define PONK_PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle(float xPos, float maxSpeed, const sf::Vector2f& size);

    void handleInput();
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
private:
    sf::RectangleShape sprite;
    const float maxSpeed;
    float yVelocity;
};

#endif //PONK_PADDLE_H
