#ifndef PONK_SCORECOUNTER_H
#define PONK_SCORECOUNTER_H

#include <SFML/Graphics.hpp>

class ScoreCounter
{
public:
    explicit ScoreCounter(sf::Font& font, const sf::Vector2f& screenSize);
    void scoreForP1();
    void scoreForP2();
    void render(sf::RenderWindow& window);

private:
    int _player1Score, _player2Score;
    sf::Text _player1ScoreText, _player2ScoreText;
};

#endif //PONK_SCORECOUNTER_H
