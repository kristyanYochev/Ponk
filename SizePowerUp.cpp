#include "SizePowerUp.h"
#include "Paddle.h"

SizePowerUp::SizePowerUp(sf::Texture& texture, const sf::Vector2f& position, MainGameScreen& mainGameScreen, float size)
        :
        PowerUp(texture, position, mainGameScreen, size)
{ }

void SizePowerUp::applyTo(Paddle* paddle)
{
    paddle->setHeightScale(1.5f);
}

void SizePowerUp::removeFrom(Paddle* paddle)
{
    paddle->setHeightScale(1.f);
}
