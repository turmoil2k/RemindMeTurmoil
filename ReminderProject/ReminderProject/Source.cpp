#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "window.viroos.hhh.ez");
    sf::CircleShape shapeR(20.f);
    shapeR.setFillColor(sf::Color::Red);
    sf::CircleShape shapeG(20.f);
    shapeG.setPosition(20, 0);
    shapeG.setFillColor(sf::Color::Green);
    sf::CircleShape shapeB(20.f);
    shapeB.setPosition(40, 0);
    shapeB.setFillColor(sf::Color::Blue);

    bool testWindow = true;
    if (testWindow)
    {
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shapeR);
            window.draw(shapeG);
            window.draw(shapeB);
            window.display();
        }
    }
    else
    {
        std::cout << "Testing Window False" << "\n";
    }

	return 0;
}