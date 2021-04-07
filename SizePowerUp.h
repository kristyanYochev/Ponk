#ifndef PONK_SIZEPOWERUP_H
#define PONK_SIZEPOWERUP_H

#include "PowerUp.h"

class SizePowerUp : public PowerUp
{
public:
    SizePowerUp(sf::Texture& texture, const sf::Vector2f& position, MainGameScreen& mainGameScreen, float size = 1.f);
    void applyTo(Paddle* paddle) override;
    void removeFrom(Paddle* paddle) override;
};

#endif //PONK_SIZEPOWERUP_H
