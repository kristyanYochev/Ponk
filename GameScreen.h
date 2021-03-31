#ifndef PONK_GAMESCREEN_H
#define PONK_GAMESCREEN_H

#include <memory>

class GameScreen
{
public:
    virtual ~GameScreen() = default;
    virtual std::unique_ptr<GameScreen> show() = 0;
};

#endif //PONK_GAMESCREEN_H
