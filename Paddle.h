#ifndef PONK_PADDLE_H
#define PONK_PADDLE_H

#include <SFML/Graphics.hpp>

class Game;

class Paddle
{
public:
    Paddle(
            float xPos,
            float maxSpeed,
            const sf::Vector2f& size,
            Game& game,
            sf::Keyboard::Key upKey = sf::Keyboard::W,
            sf::Keyboard::Key downKey = sf::Keyboard::S
    );

    void handleInput();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float interpolationFactor);
    sf::FloatRect boundingRect() const;

private:
    sf::RectangleShape _sprite;
    sf::Keyboard::Key _upKey;
    sf::Keyboard::Key _downKey;
    const float _maxSpeed;
    float _yVelocity;
    sf::Vector2f _position;
    Game& _game;
};

#endif //PONK_PADDLE_H
