#ifndef PONK_PLAYERWINSSCREEN_H
#define PONK_PLAYERWINSSCREEN_H

#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "Game.h"

class PlayerWinsScreen : public GameScreen
{
public:
    PlayerWinsScreen(unsigned int playerNumber, Game& game);
    std::unique_ptr<GameScreen> show() override;
private:
    sf::Text _text;
    sf::RenderWindow& _window;
    Game& _game;
};

#endif //PONK_PLAYERWINSSCREEN_H
