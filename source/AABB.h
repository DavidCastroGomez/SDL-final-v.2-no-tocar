#pragma once
#include "Vector2.h"
class AABB
{
private:
	Vector2 topLeft;
	Vector2 size;
public:
	AABB() = default;
	AABB(Vector2, Vector2);
	bool CheckOverlappingAABB(const AABB*);
	bool CheckOverlappingPoint(Vector2);
	Vector2 GetTopLeft();
	Vector2 GetSize();
	void SetTopLeft(Vector2);
	void SetSize(Vector2);
};

