#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <string>

//Wrapper class acting like a "Game Engine"

class Game
{
private:
	//Private Variables!
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	//Private Functions!
	void InitVariables();
	void InitWindow();

public:
	//Constructors
	Game(int x, int y);
	Game();
	//Destructors
	virtual ~Game();

	//Accessors
	const bool GetWindowIsOpen() const;
	
	//Functions
	void PollEvents();
	void Update();
	void Render();


};

