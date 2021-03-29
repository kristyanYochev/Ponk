#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Common.h"
#include "Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Ponk");

    Paddle paddle(50.f, 2000.f, sf::Vector2f(10.f, 100.f));
    Paddle secondPaddle(
            SCREEN_SIZE.x - 50.f,
            2000.f,
            sf::Vector2f(10.f, 100.f),
            sf::Keyboard::Up,
            sf::Keyboard::Down
    );

    Ball ball(1500.f);

    sf::Clock clk;

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) ball.start();
        }

        paddle.handleInput();
        secondPaddle.handleInput();

        const float deltaTime = clk.getElapsedTime().asSeconds();
        clk.restart();

        paddle.update(deltaTime);
        secondPaddle.update(deltaTime);
        ball.update(deltaTime);

        window.clear();
        paddle.render(window);
        secondPaddle.render(window);
        ball.render(window);
        window.display();
    }

    return 0;
}
