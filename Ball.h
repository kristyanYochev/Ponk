#ifndef PONK_BALL_H
#define PONK_BALL_H

#include <SFML/Graphics.hpp>

class Paddle;
class ScoreCounter;

class Ball
{
public:
    Ball(float maxSpeed, Paddle& paddle1, Paddle& paddle2, ScoreCounter& counter, float size = 10.f);

    void start();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float interpolationFactor);

private:
    bool collidesWith(const Paddle& paddle, sf::FloatRect& intersection) const;
    sf::FloatRect boundingRect() const;
    void handlePaddleCollision(const Paddle& paddle);
    void handleScreenBorderCollision();
    void reset();

    const float maxSpeed;
    sf::RectangleShape sprite;
    sf::Vector2f velocity;
    sf::Vector2f position;
    const Paddle& paddle1;
    const Paddle& paddle2;
    ScoreCounter& counter;
};

#endif //PONK_BALL_H
