#include "AABB.h"

AABB::AABB(Vector2 topLeft, Vector2 size)
{
	this->topLeft = topLeft;
	this->size = size;
}

bool AABB::CheckOverlappingAABB(AABB* b)
{
    Vector2 leftUpA, leftUpB;
    Vector2 leftDownA, leftDownB;
    Vector2 rightUpA, rightUpB;
    Vector2 rightDownA, rightDownB;

    //Calculate the sides of rect A
    leftUpA = this->topLeft;
    leftDownA = Vector2(this->topLeft.x, this->topLeft.y + size.y);
    rightUpA = Vector2(this->topLeft.x + this->size.x, this->topLeft.y);
    rightDownA = Vector2(this->topLeft.x + this->size.x, this->topLeft.y + this->size.y);

    //Calculate the sides of rect B
    leftUpB = b->GetTopLeft();
    leftDownB = Vector2(b->GetTopLeft().x, b->GetTopLeft().y + b->GetSize().y);
    rightUpB = Vector2(b->GetTopLeft().x + b->GetSize().x, b->GetTopLeft().y);
    rightDownB = Vector2(b->GetTopLeft().x + b->GetSize().x, b->GetTopLeft().y + b->GetSize().y);

    //If any of the sides from A are outside of B
    if (leftUpA.x <= rightDownB.x && leftUpA.y >= rightDownB.y)
    {
        return true;
    }

    if (leftDownA.x <= rightUpB.x && leftDownA.y >= rightUpB.y)
    {
        return true;
    }

    if (rightUpA.x <= leftDownB.x && rightUpA.y >= leftDownB.y)
    {
        return true;
    }

    if (rightDownA.x <= leftUpB.x && rightDownA.y >= leftUpB.y)
    {
        return true;
    }

    //If none of the sides from A are outside B
    return false;
}

bool AABB::CheckOverlappingPoint(Vector2 point)
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
