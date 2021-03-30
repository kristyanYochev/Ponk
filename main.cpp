#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Common.h"
#include "Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Ponk");

    Paddle paddle(50.f, 1500.f, sf::Vector2f(10.f, 100.f));
    Paddle secondPaddle(
            SCREEN_SIZE.x - 50.f,
            2000.f,
            sf::Vector2f(10.f, 100.f),
            sf::Keyboard::Up,
            sf::Keyboard::Down
    );

    Ball ball(1000.f, paddle, secondPaddle);

    sf::Clock clk;

    const float updateTimestep = 1 / 50.f;
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

        paddle.handleInput();
        secondPaddle.handleInput();

        while (lag >= updateTimestep)
        {
            paddle.update(updateTimestep);
            secondPaddle.update(updateTimestep);
            ball.update(updateTimestep);
            lag -= updateTimestep;
        }

        window.clear();
        paddle.render(window, lag);
        secondPaddle.render(window, lag);
        ball.render(window, lag);
        window.display();
    }

    return 0;
}
