#pragma once
#include "Vector2TEST.h"
class Vector3TEST : public Vector2TEST
{
private:
	float posZ = 0;

public:
	Vector3TEST(float x, float y, float z);
	void PrintPosition();

	float getZ()
	{
		return posZ;
	}
};

/*
tested in main

Vector2TEST vec2T(10, 20);

vec2T.PrintPosition();

Vector3TEST vec3T(10, 20, 30);

vec3T.PrintPosition();

//std::cout << vec3T.posX << "\n";
std::cout << vec3T.getX() << vec3T.getZ() << "\n";
*/