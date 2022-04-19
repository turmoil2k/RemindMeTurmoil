#include <chrono>
#include <ctime>
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    int windowWidth = 1920;
    int windowHeight = 1080;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "window.viroos.hhh.ez");

    sf::CircleShape shapeR(20.f);
    shapeR.setFillColor(sf::Color::Red);
    sf::CircleShape shapeG(20.f);
    shapeG.setPosition(20, 0);
    shapeG.setFillColor(sf::Color::Green);
    sf::CircleShape shapeB(20.f);
    shapeB.setPosition(40, 0);
    shapeB.setFillColor(sf::Color::Blue);
    
    sf::Vector2f size(25, 25);

    sf::RectangleShape rect(size);
    rect.setPosition(50, 50);
    rect.setFillColor(sf::Color::White);

    sf::Vector2f rectBarSize(windowWidth/6, windowHeight);
    sf::RectangleShape rectBar(rectBarSize);
    rectBar.setPosition(windowWidth/12, 0);
    sf::Color rectBarCol(50, 50, 50,200);
    rectBar.setFillColor(rectBarCol);

    sf::Font openSansFont;
    if (!openSansFont.loadFromFile("all/opensans.ttf"))
    {
        std::cout << "Fail loading Font!!!" << "\n";
        // error...
    }
    else
    {
        std::cout << "working font" << "\n";
        // working...
    }

    sf::Text titleText("Welcome to Turmoil's Reminder", openSansFont, 75);
    titleText.setPosition(windowWidth/3.5f, 10);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("all/bg.jpg"))
    {
        std::cout << "Fail loading Texutre!!!" << std::endl;
    }
    else
    {
        std::cout << "working tex" << "\n";
        // working...
    }
    //testpush
    sf::Sprite sprite(backgroundTexture);

    sf::Vector2f targetSize(windowWidth, windowHeight);

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width,
        targetSize.y / sprite.getLocalBounds().height);

    time_t result = time(NULL);
    char str[50];
    ctime_s(str, sizeof str, &result);
    //strftime(str, sizeof str, "%r", &start);
    printf("%s", str);
    
    /*put in update for time
        result = time(NULL);
        ctime_s(str, sizeof str, &result);
        printf("%s", str);
    */

    bool testWindow = true;
    if (testWindow)
    {
        while (window.isOpen())
        {
            sf::Event event;
            //https://www.sfml-dev.org/tutorials/2.5/window-events.php
            //EVENTS ARE VERY IMPORTANT TAKE THE TIME TO UNDERSTAND ALL OF THEM

            while (window.pollEvent(event))
            {
                // check the type of the event...
                switch (event.type)
                {
                        // window closed
                    case sf::Event::Closed:
                        std::cout << "trying to close" << std::endl;
                        window.close();
                        break;

                        // key pressed
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            std::cout << "pressed esc";
                            window.close();
                        }

                        if (event.key.code == sf::Keyboard::Space)
                        {
                            std::cout << "Testing space" << "\n";
                        }
                        break;

                    case sf::Event::Resized:
                        //Resizing window
                            std::cout << "Window being resized???" << std::endl;
                            //non moving background image staying at max size
                            sprite.setScale(
                                sprite.getLocalBounds().width / window.getSize().x,
                                sprite.getLocalBounds().height / window.getSize().y);
                         break;

                        // we don't process other types of events
                    default:
                        break;
                }
            }
          

            window.clear();
            window.draw(sprite);
            window.draw(titleText);
            window.draw(shapeR);
            window.draw(shapeG);
            window.draw(shapeB);
            window.draw(rect);
            window.draw(rectBar);
            window.display();
        }
    }
    else
    {
        std::cout << "Testing Window False" << "\n";
    }

	return 0;
}