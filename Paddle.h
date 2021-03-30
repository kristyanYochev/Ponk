#ifndef PONK_PADDLE_H
#define PONK_PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle(
            float xPos,
            float maxSpeed,
            const sf::Vector2f& size,
            sf::Keyboard::Key upKey = sf::Keyboard::W,
            sf::Keyboard::Key downKey = sf::Keyboard::S
    );

    void handleInput();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float interpolationFactor);
private:
    sf::RectangleShape sprite;
    sf::Keyboard::Key upKey;
    sf::Keyboard::Key downKey;
    const float maxSpeed;
    float yVelocity;
    sf::Vector2f position;
};

#endif //PONK_PADDLE_H
