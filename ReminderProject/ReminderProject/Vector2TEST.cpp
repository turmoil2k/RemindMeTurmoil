#include "Vector2TEST.h"

Vector2TEST::Vector2TEST(float x, float y)
{
	posX = x;
	posY = y;
}

void Vector2TEST::PrintPosition()
{
	std::cout << posX << "," << posY << "\n";
}
