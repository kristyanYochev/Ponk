#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ponk");

    sf::RectangleShape paddle(sf::Vector2f(10.f, 100.f));
    paddle.setPosition(0, 0);
    const float paddleMaxSpeed = 2000.f;
    float paddleSpeed;

    sf::Clock clk;

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        paddleSpeed = 0;
        paddleSpeed += sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? paddleMaxSpeed : 0;
        paddleSpeed += sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? -paddleMaxSpeed : 0;

        paddle.move(0, paddleSpeed * clk.getElapsedTime().asSeconds());

        clk.restart();
        window.clear();
        window.draw(paddle);
        window.display();
    }

    return 0;
}
