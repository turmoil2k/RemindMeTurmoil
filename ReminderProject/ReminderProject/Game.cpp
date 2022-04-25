#include "Game.h"

//Private Functions!
void Game::InitVariables()
{
	this->window = nullptr;

    int windowWidth = 1920;
    int windowHeight = 1080;

    sf::CircleShape shapeR(20.f);
    shapeR.setFillColor(sf::Color::Red);
    sf::CircleShape shapeG(20.f);
    shapeG.setPosition(20, 0);
    shapeG.setFillColor(sf::Color::Green);
    sf::CircleShape shapeB(20.f);
    shapeB.setPosition(40, 0);
    shapeB.setFillColor(sf::Color::Blue);
    sf::CircleShape shapeW(20.f);
    shapeW.setFillColor(sf::Color::White);


    sf::Vector2f rectBarSize(windowWidth / 6, windowHeight);
    sf::RectangleShape rectBar(rectBarSize);
    rectBar.setPosition(windowWidth / 12, 0);
    sf::Color rectBarCol(50, 50, 50, 200);
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
    titleText.setPosition(windowWidth / 3.5f, 10);

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
    printf("%s", str);
    std::string timeStr = str;

    sf::Text timet("Welcome to Turmoil's Reminder", openSansFont, 75);
    timet.setPosition(windowWidth / 3.5f, 10);

    sf::Text timeText;
    timeText.setFont(openSansFont);
    timeText.setCharacterSize(200);
    timeText.setPosition(windowWidth / 2, windowHeight / 3);
    shapeW.setPosition(windowWidth / 2, windowHeight / 3);

    sf::Vector2f timeRectSize(25, 25);
    sf::RectangleShape timeRect(timeRectSize);
    timeRect.setPosition(windowWidth - 100, windowHeight / 2.25);
    timeRect.setFillColor(sf::Color::White);

    sf::Vector2i mousePos(0, 0);
}

void Game::InitWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "window.viroos.hhh.ez");
}


//Constructors / Destructors

Game::Game(int x, int y)
{
	this->InitVariables();
	this->InitWindow();
}

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::GetWindowIsOpen() const
{
	return this->window->isOpen();
}


void Game::PollEvents()
{
    //https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //EVENTS ARE VERY IMPORTANT TAKE THE TIME TO UNDERSTAND ALL OF THEM
    while (this->window->pollEvent(this->sfmlEvent))
    {
        // check the type of the event...
        switch (this->sfmlEvent.type)
        {
            // window closed
        case sf::Event::Closed:
            std::cout << "trying to close" << std::endl;
            this->window->close();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
            {
                std::cout << "pressed esc";
                this->window->close();
            }

            if (this->sfmlEvent.key.code == sf::Keyboard::Space)
            {
                std::cout << "Testing space" << "\n";
            }
            break;

        case sf::Event::Resized:
            //Resizing window
            std::cout << "Window being resized???" << std::endl;
            //non moving background image staying at max size
           // sprite.setScale(
           //     sprite.getLocalBounds().width / window.getSize().x,
           //     sprite.getLocalBounds().height / window.getSize().y);
            break;
        case sf::Event::MouseButtonPressed:
            std::cout << "Mouse clicked!" << "\n";
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << "Mouse Left Click!" << "\n";
            }
            // get global mouse position
            //mousePos = sf::Mouse::getPosition(window);
            //std::cout << "Mouse Position is X/Y" << mousePos.x << " " << mousePos.y << "\n";
            break;

            // we don't process other types of events
        default:
            break;
        }
    }
}

//IMPLEMENTING FUNCTIONS FROM GAME.H
void Game::Update()
{
	this->PollEvents();
}

void Game::Render()
{
    this->window->clear();
    /*
    this->window.draw(sprite);
    this->window.draw(titleText);
    this->window.draw(timeText);
    this->window.draw(shapeR);
    this->window.draw(shapeG);
    this->window.draw(shapeB);
    this->window.draw(shapeW);
    this->window.draw(timeRect);
    this->window.draw(rectBar);
    */
    this->window->display();
}
