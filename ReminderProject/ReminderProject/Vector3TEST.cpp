#include "Vector3TEST.h"

Vector3TEST::Vector3TEST(float x, float y, float z) : Vector2TEST::Vector2TEST(x, y)
{
	posZ = z;
}



void Vector3TEST::PrintPosition()
{
	std::cout << posX << "," << posY << "," << posZ << "\n";
}

