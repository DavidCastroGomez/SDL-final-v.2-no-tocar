#include "DivingTurtles.h"

DivingTurtles::DivingTurtles(float diveDuration, float surfaceDuration, int length) : Turtles(length)
{
	this->diveDuration = diveDuration;
	this->surfaceDuration = surfaceDuration;
}

void DivingTurtles::Update()
{
}

void DivingTurtles::Render()
{
}

bool DivingTurtles::isDiving()
{
	return false;
}
