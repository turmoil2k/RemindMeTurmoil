#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <string>


#include "Button.h"

//Wrapper class acting like a "Game Engine"

class Game
{
private:
	//Private Variables!
	sf::RenderWindow* window = nullptr;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	sf::View view;

	//Private Objects!
	//(CREATE OBJECTS HERE & SET THEM IN INIT VARS)
	sf::CircleShape shapeR;
	sf::CircleShape shapeG;
	sf::CircleShape shapeB;
	sf::CircleShape shapeW;

	sf::Vector2f rectBarSize;
	sf::RectangleShape rectBar;

	sf::Texture backgroundTexture;
	sf::Sprite sprite;
	sf::Vector2f spriteTargetSize;

	sf::Font openSansFont;
	sf::Text titleText;

	sf::CircleShape timeCircle;
	sf::RectangleShape timeRect;

	Button* timeButtonTest;
	std::string buttonTestString;

	sf::Vector2i mousePos;

	char str[50];
	sf::Text timeText;
	std::string timeStr;



	//Private Functions!
	void InitVariables();
	void InitWindow(int initWidth, int initHeight, int fpsLimit);


public:
	//Constructors
	Game(int windowWidth, int windowHeight, int fpsLimit);
	Game();
	//Destructors
	virtual ~Game();

	//Accessors
	const bool GetWindowIsOpen() const;
	
	//Functions
	void PollEvents();
	void Update();
	void Render();
	void UpdateTime();
	void UpdateButtons();

};

