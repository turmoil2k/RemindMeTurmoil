#include "Game.h"

//Private Functions!
void Game::InitVariables()
{
    shapeR.setRadius(20.f);
    shapeR.setFillColor(sf::Color::Red);
    shapeG.setRadius(20.f);
    shapeG.setPosition(20, 0);
    shapeG.setFillColor(sf::Color::Green);
    shapeB.setRadius(20.f);
    shapeB.setPosition(40, 0);
    shapeB.setFillColor(sf::Color::Blue);
    shapeW.setRadius(20.f);
    shapeW.setFillColor(sf::Color::White);

    rectBarSize.x = videoMode.width / 6;
    rectBarSize.y = videoMode.height;
    rectBar.setSize(rectBarSize);
    rectBar.setPosition(videoMode.width / 12, 0);
    sf::Color rectBarCol(50, 50, 50, 200);
    rectBar.setFillColor(rectBarCol);

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

    titleText.setString("Welcome to Turmoil's Reminder");
    titleText.setFont(openSansFont);
    titleText.setCharacterSize(75);
    titleText.setPosition(videoMode.width / 3.5f, 10);

    if (!backgroundTexture.loadFromFile("all/bg.jpg"))
    {
        std::cout << "Fail loading Texutre!!!" << std::endl;
    }
    else
    {
        std::cout << "working tex" << "\n";
        // working...
    }

    sprite.setTexture(backgroundTexture);

    spriteTargetSize.x = videoMode.width;
    spriteTargetSize.y = videoMode.height;

    sprite.setScale(
        spriteTargetSize.x / sprite.getLocalBounds().width,
        spriteTargetSize.y / sprite.getLocalBounds().height);

    
    timeText.setFont(openSansFont);
    timeText.setCharacterSize(200);
    timeText.setPosition(videoMode.width / 2, videoMode.height / 3);
    shapeW.setPosition(videoMode.width / 2, videoMode.height / 3);

    timeCircle.setRadius(25);
    timeCircle.setPosition((videoMode.width - 100) - 12.5f, (videoMode.height / 2.25) - 12.5f);
    timeCircle.setFillColor(sf::Color::Blue);

    timeRect.setSize(sf::Vector2f(25, 25));
    timeRect.setPosition((videoMode.width - 100), (videoMode.height / 2.25));
    timeRect.setFillColor(sf::Color::Cyan);

    //timeButtonTest = new Button((videoMode.width - 100), (videoMode.height / 2.25) + 50, 25, 25, sf::Color(50,50,50,100),sf::Color(150,150,150,200), sf::Color(50, 255, 50, 255));
    timeButtonTest = new Button((600), (200), 100, 50, sf::Color(50, 50, 50, 100), sf::Color(150, 150, 150, 200), sf::Color(50, 255, 50, 255));
    buttonTestString = "24H";
}

void Game::InitWindow(int initWidth, int initHeight,int fpsLimit)
{
    this->videoMode.width = initWidth;
    this->videoMode.height = initHeight;
    this->window = new sf::RenderWindow(this->videoMode, "window.viroos.hhh.ez");
    this->view.setCenter(sf::Vector2f(initWidth/2, initHeight/2));
    this->view.setSize(sf::Vector2f(initWidth,initHeight));
    this->window->setView(this->view);
    this->window->setFramerateLimit(fpsLimit);
}

//Constructors / Destructors

Game::Game(int windowWidth, int windowHeight, int fpsLimit)
{
    this->InitWindow(windowWidth, windowHeight, fpsLimit);
	this->InitVariables();
}

Game::Game()
{
	this->InitWindow(800,600,60);
	this->InitVariables();
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
            sprite.setScale(
                sprite.getLocalBounds().width / this->window->getSize().x,
                sprite.getLocalBounds().height / this->window->getSize().y);

            this->view.setCenter(sf::Vector2f(window->getSize().x/2, window->getSize().y/2));
            this->view.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

            std::cout << window->getSize().x << " " << window->getSize().y << "\n";
            break;


        case sf::Event::MouseButtonPressed:

            std::cout << "Mouse clicked!" << "\n";
            this->timeButtonTest->UpdateButton(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)),true);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << "Mouse Left Click!" << "\n";
            }
            //get global mouse position
            mousePos = sf::Mouse::getPosition(*this->window);
            std::cout << "Mouse Position is X/Y" << mousePos.x << " " << mousePos.y << "\n";
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
    this->UpdateTime();
	this->PollEvents();
}

void Game::Render()
{
    this->window->clear();
    
    this->window->draw(sprite);

    this->window->draw(shapeR);
    this->window->draw(shapeG);
    this->window->draw(shapeB);
    this->window->draw(shapeW);

    this->window->draw(timeCircle);
    this->window->draw(timeRect);
    this->window->draw(rectBar);

    this->window->draw(titleText);
    this->window->draw(timeText);

    timeButtonTest->RenderButton(window);
    
    this->window->display();
}

void Game::UpdateTime()
{
    time_t result = time(NULL);
    ctime_s(str, sizeof str, &result);
    //printf("%s", str); //std::cout << str;
    timeStr = str;
    timeText.setString(timeStr.substr(11, 8));
    //std::cout << timeStr.substr(11, 8) << "\n";

    //this->timeButtonTest->UpdateButton((sf::Vector2f)sf::Mouse::getPosition(*this->window));

    this->timeButtonTest->UpdateButton(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)));

    if (timeButtonTest->GetToggleState())
    {
        buttonTestString = "12H MODE";
    }
    else
    {
        buttonTestString = "24H MODE";
    }

    std::cout << timeButtonTest->GetToggleState() << "\n";
    std::cout << buttonTestString << "\n";
}
