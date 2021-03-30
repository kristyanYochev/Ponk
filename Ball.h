#ifndef PONK_BALL_H
#define PONK_BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:
    explicit Ball(float maxSpeed, float size = 10.f);

    void start();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float interpolationFactor);
private:
    const float maxSpeed;
    sf::RectangleShape sprite;
    sf::Vector2f velocity;
    sf::Vector2f position;
};

#endif //PONK_BALL_H
