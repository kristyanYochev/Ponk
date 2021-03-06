#include "ScoreCounter.h"
#include "MainGameScreen.h"

ScoreCounter::ScoreCounter(sf::Font& font, MainGameScreen& mainGameScreen, unsigned maxScore)
        :
        _player1Score(0),
        _player2Score(0),
        _player1ScoreText("0", font),
        _player2ScoreText("0", font),
        _maxScore(maxScore),
        _mainGameScreen(mainGameScreen)
{
    _player1ScoreText.setFillColor(sf::Color::White);
    _player2ScoreText.setFillColor(sf::Color::White);

    const sf::Vector2f& screenSize = mainGameScreen.screenSize();

    _player1ScoreText.setPosition(screenSize.x / 4.f, screenSize.y / 20.f);
    _player2ScoreText.setPosition(screenSize.x * 3.f / 4.f, screenSize.y / 20.f);

    _player1ScoreText.setScale(3.f, 3.f);
    _player2ScoreText.setScale(3.f, 3.f);
}

void ScoreCounter::scoreForP1()
{
    ++_player1Score;
    if (_player1Score >= _maxScore)
    {
        _mainGameScreen.playerWon(1);
    }
    _player1ScoreText.setString(std::to_string(_player1Score));
}

void ScoreCounter::scoreForP2()
{
    ++_player2Score;
    if (_player2Score >= _maxScore)
    {
        _mainGameScreen.playerWon(2);
    }
    _player2ScoreText.setString(std::to_string(_player2Score));
}

void ScoreCounter::render(sf::RenderWindow& window)
{
    window.draw(_player1ScoreText);
    window.draw(_player2ScoreText);
}
