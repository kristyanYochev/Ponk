#include "Game.h"

Game::Game(sf::Vector2f screenSize, sf::Font& scoreCounterFont)
        :
        _screenSize(screenSize),
        window(sf::VideoMode(screenSize.x, screenSize.y), "Ponk"),
        paddle1(50.f, 1500.f, sf::Vector2f(10.f, 100.f)),
        paddle2(
                screenSize.x - 50.f,
                2000.f,
                sf::Vector2f(10.f, 100.f),
                sf::Keyboard::Up,
                sf::Keyboard::Down
        ),
        counter(scoreCounterFont),
        ball(1000.f, paddle1, paddle2, counter)
{ }

void Game::run()
{
    sf::Clock clk;

    const float updateTimestep = 1 / 120.f;
    float lag = 0;

    while (window.isOpen())
    {
        lag += clk.getElapsedTime().asSeconds();
        clk.restart();

        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) ball.start();
        }

        paddle1.handleInput();
        paddle2.handleInput();

        while (lag >= updateTimestep)
        {
            paddle1.update(updateTimestep);
            paddle2.update(updateTimestep);
            ball.update(updateTimestep);
            lag -= updateTimestep;
        }

        window.clear();

        paddle1.render(window, lag);
        paddle2.render(window, lag);
        ball.render(window, lag);
        counter.render(window);

        window.display();
    }
}

const sf::Vector2f& Game::screenSize() const
{
    return _screenSize;
}
