#ifndef PONK_SCORECOUNTER_H
#define PONK_SCORECOUNTER_H

#include <SFML/Graphics.hpp>

class MainGameScreen;

class ScoreCounter
{
public:
    ScoreCounter(sf::Font& font, MainGameScreen& mainGameScreen, unsigned maxScore);
    void scoreForP1();
    void scoreForP2();
    void render(sf::RenderWindow& window);

private:
    unsigned _player1Score, _player2Score;
    const unsigned _maxScore;
    MainGameScreen& _mainGameScreen;
    sf::Text _player1ScoreText, _player2ScoreText;
};

#endif //PONK_SCORECOUNTER_H
