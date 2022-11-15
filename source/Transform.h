#pragma once
#include "Vector2.h"

class Transform
{
public:
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;

	Transform() = default;
	Transform(Vector2, Vector2, Vector2);
};

