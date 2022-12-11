#include "Frog.h"

Frog::Frog()
{
	moving = false;
	hasFood = false;
	food = nullptr;
}

void Frog::Respawn()
{

}

void Frog::AddMovement(Vector2 dir)
{

}

bool Frog::isMoving()
{
	return moving;
}

void Frog::AddFood(Food* food)
{
	this->food = food;
	if (!hasFood)
		hasFood = true;
}