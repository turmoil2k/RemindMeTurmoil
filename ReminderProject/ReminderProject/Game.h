#pragma once
class Game
{
private:

	//Private Functions!
	void InitVariables();
	void InitWindow();

public:
	//Constructors
	Game();
	//Destructors
	virtual ~Game();

	//Accessors
	
	
	//Functions
	void Update();
	void Render();


};

