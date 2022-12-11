#include "DivingTurtles.h"

DivingTurtles::DivingTurtles(float diveDuration, float surfaceDuration, int length) : Turtles(length)
{
	this->diveDuration = diveDuration;
	this->surfaceDuration = surfaceDuration;
}