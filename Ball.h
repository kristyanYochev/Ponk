#ifndef PONK_BALL_H
#define PONK_BALL_H

#include <SFML/Graphics.hpp>

class MainGameScreen;
class Paddle;

class Ball
{
public:
    Ball(float maxSpeed, MainGameScreen& mainGameScreen, float size = 10.f);

    void start();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float interpolationFactor);

    void reset();

    sf::FloatRect boundingRect() const;
    Paddle * lastHitPaddle();
private:
    bool collidesWith(const Paddle& paddle, sf::FloatRect& intersection) const;
    void handlePaddleCollision(Paddle& paddle);
    void handleScreenBorderCollision();

    const float _maxSpeed;
    sf::RectangleShape _sprite;
    sf::Vector2f _velocity;
    sf::Vector2f _position;
    MainGameScreen& _mainGameScreen;
    Paddle * _lastHitPaddle;
};

#endif //PONK_BALL_H
