#include "SpeedPowerUp.h"
#include "Paddle.h"

SpeedPowerUp::SpeedPowerUp(sf::Texture& texture, const sf::Vector2f& position, MainGameScreen& mainGameScreen,
        float size)
        :
        PowerUp(texture, position, mainGameScreen, size)
{ }

void SpeedPowerUp::applyTo(Paddle* paddle)
{
    paddle->scaleSpeed(1.5f);
}

void SpeedPowerUp::removeFrom(Paddle* paddle)
{
    paddle->scaleSpeed(1.f / 1.5f);
}
