#include "Turtles.h"

Turtles::Turtles(int length)
{
	this->length = length;
}

void Turtles::Update()
{
	transform.position.x += -8 * TM->GetDeltaTime();
}

void Turtles::Render()
{
}
