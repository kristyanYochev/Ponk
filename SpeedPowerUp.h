#ifndef PONK_SPEEDPOWERUP_H
#define PONK_SPEEDPOWERUP_H

#include "PowerUp.h"

class SpeedPowerUp : public PowerUp
{
public:
    SpeedPowerUp(sf::Texture& texture, const sf::Vector2f& position, MainGameScreen& mainGameScreen, float size = 1.f);

    void applyTo(Paddle* paddle) override;
    void removeFrom(Paddle* paddle) override;
};

#endif //PONK_SPEEDPOWERUP_H
