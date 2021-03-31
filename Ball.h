#ifndef PONK_BALL_H
#define PONK_BALL_H

#include <SFML/Graphics.hpp>

class Game;
class Paddle;

class Ball
{
public:
    Ball(float maxSpeed, Game& game, float size = 10.f);

    void start();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float interpolationFactor);

    void reset();
private:
    bool collidesWith(const Paddle& paddle, sf::FloatRect& intersection) const;
    sf::FloatRect boundingRect() const;
    void handlePaddleCollision(const Paddle& paddle);
    void handleScreenBorderCollision();

    const float _maxSpeed;
    sf::RectangleShape _sprite;
    sf::Vector2f _velocity;
    sf::Vector2f _position;
    Game& _game;
};

#endif //PONK_BALL_H
