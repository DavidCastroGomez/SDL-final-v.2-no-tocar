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
	moving = true;
	transform.position.x += dir.x;
	transform.position.y += dir.y;
	moving = false;
}

bool Frog::isMoving()
{
	return moving;
}

void Frog::AddFood(Food* food)
{
	this->food = food;
	hasFood = true;
	this->food->AttachToPlayer();
}

void Frog::Update()
{	
	if (!isMoving())
	{
		Vector2 dir;
		if (IM->CheckKeyState(SDLK_w, PRESSED))
		{
			dir.x = 0;
			dir.y = 16;
		}
		if (IM->CheckKeyState(SDLK_s, PRESSED))
		{
			dir.x = 0;
			dir.y = -16;
		}
		if (IM->CheckKeyState(SDLK_d, PRESSED))
		{
			dir.x = 16;
			dir.y = 0;
		}
		if (IM->CheckKeyState(SDLK_a, PRESSED))
		{
			dir.x = -16;
			dir.y = 0;
		}
		AddMovement(dir);
	}
}