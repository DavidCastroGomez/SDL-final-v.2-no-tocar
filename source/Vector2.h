#pragma once
#include <math.h>
class Vector2
{
public:
	float x;
	float y;

	Vector2() = default;
	Vector2(float, float);
	void Normalize();

};

