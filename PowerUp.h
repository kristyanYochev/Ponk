#ifndef PONK_POWERUP_H
#define PONK_POWERUP_H

#include <SFML/Graphics.hpp>

class Paddle;
class MainGameScreen;

class PowerUp
{
public:
    PowerUp(sf::Texture& texture, const sf::Vector2f& position, MainGameScreen& mainGameScreen, float size = 1.f);
    virtual ~PowerUp() = default;
    void render(sf::RenderWindow& window);
    void update();

    virtual void applyTo(Paddle * paddle) = 0;
    virtual void removeFrom(Paddle * paddle) = 0;
private:
    sf::Sprite _sprite;
    MainGameScreen& _mainGameScreen;
};

#endif //PONK_POWERUP_H
