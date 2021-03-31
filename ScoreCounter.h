#ifndef PONK_SCORECOUNTER_H
#define PONK_SCORECOUNTER_H

#include <SFML/Graphics.hpp>

class ScoreCounter
{
public:
    explicit ScoreCounter(sf::Font& font);
    void scoreForP1();
    void scoreForP2();
    void render(sf::RenderWindow& window);

private:
    int player1Score, player2Score;
    sf::Text player1ScoreText, player2ScoreText;
};

#endif //PONK_SCORECOUNTER_H
