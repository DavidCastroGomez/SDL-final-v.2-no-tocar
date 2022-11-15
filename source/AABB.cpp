#include "AABB.h"

AABB::AABB(Vector2 topLeft, Vector2 size)
{
	this->topLeft = topLeft;
	this->size = size;
}

bool AABB::CheckOverlappingAABB(const AABB*)
{
	//TODO CheckOverlappingAABB
	return false;
}

bool AABB::CheckOverlappingPoint(Vector2)
{
	//TODO CheckOverlappingPoint
	return false;
}

Vector2 AABB::GetTopLeft()
{
	return topLeft;
}

Vector2 AABB::GetSize()
{
	return size;
}

void AABB::SetTopLeft(Vector2 topLeft)
{
	this->topLeft = topLeft;
}

void AABB::SetSize(Vector2 size)
{
	this->size = size;
}
