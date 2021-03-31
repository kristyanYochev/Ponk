#include "ScoreCounter.h"
#include "Common.h"

ScoreCounter::ScoreCounter(sf::Font& font)
        :
        player1Score(0),
        player2Score(0),
        player1ScoreText("0", font),
        player2ScoreText("0", font)
{
    player1ScoreText.setFillColor(sf::Color::White);
    player2ScoreText.setFillColor(sf::Color::White);

    player1ScoreText.setPosition(SCREEN_SIZE.x / 4.f, SCREEN_SIZE.y / 10.f);
    player2ScoreText.setPosition(SCREEN_SIZE.x * 3.f / 4.f, SCREEN_SIZE.y / 10.f);

    player1ScoreText.setScale(3.f, 3.f);
    player2ScoreText.setScale(3.f, 3.f);
}

void ScoreCounter::scoreForP1()
{
    ++player1Score;
    player1ScoreText.setString(std::to_string(player1Score));
}

void ScoreCounter::scoreForP2()
{
    ++player2Score;
    player2ScoreText.setString(std::to_string(player2Score));
}

void ScoreCounter::render(sf::RenderWindow& window)
{
    window.draw(player1ScoreText);
    window.draw(player2ScoreText);
}
