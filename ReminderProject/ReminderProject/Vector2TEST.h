#pragma once
#include <iostream>

class Vector2TEST
{
protected:
	float posX = 0;
	float posY = 0;

public:
	Vector2TEST(float x, float y);
	void PrintPosition();

	float getX()
	{
		return posX;
	}

	float getY()
	{
		return posY;
	}
};

