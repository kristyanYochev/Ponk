#include <SFML/Graphics.hpp>
#include "Paddle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ponk");

    Paddle paddle(50.f, 2000.f, sf::Vector2f(10.f, 100.f));

    sf::Clock clk;

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        paddle.handleInput();
        paddle.update(clk.getElapsedTime().asSeconds());

        clk.restart();
        window.clear();
        paddle.render(window);
        window.display();
    }

    return 0;
}
