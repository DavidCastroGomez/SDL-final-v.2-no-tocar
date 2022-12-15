#include "DivingTurtles.h"

DivingTurtles::DivingTurtles(float diveDuration, float surfaceDuration, int length) : Turtles(length)
{
	this->diveDuration = diveDuration;
	this->surfaceDuration = surfaceDuration;
	this->length = length;
}

void DivingTurtles::Render()
{

}

void DivingTurtles::Update()
{
	if (TM->GetCurrentTime() - TM->GetDeltaTime() > diveDuration && IsDiving())
	{
		isDiving = false;
	}
	else if (TM->GetCurrentTime() - TM->GetDeltaTime() > surfaceDuration && !IsDiving())
	{
		isDiving = true;
	}
	transform.position.x -= 8 * TM->GetDeltaTime();
}

bool DivingTurtles::IsDiving()
{
	return isDiving;
}
