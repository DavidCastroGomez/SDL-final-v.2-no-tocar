#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::Normalize()
{
	float length = (float)sqrt(pow(x, 2) * pow(y, 2));
	x = x / length;
	y = y / length;
}
