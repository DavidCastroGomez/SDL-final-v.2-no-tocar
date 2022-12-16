#include "Frog.h"

Frog::Frog()
{
	moving = false;
	hasFood = false;
	food = nullptr;
	currentRow = 1;
	lastRow = currentRow;
}

void Frog::Respawn()
{
	AddMovement(initialPosition);
}

void Frog::AddMovement(Vector2 dir)
{
	moving = true;
	transform.position.x += dir.x * TM->GetDeltaTime();
	transform.position.y += dir.y * TM->GetDeltaTime();
	currentRow = transform.position.x / 16;
	if (currentRow > lastRow)
	{
		lastRow = currentRow;
		AddScore(10);
	}
	moving = false;
}

bool Frog::isMoving()
{
	return moving;
}

void Frog::AddScore(int score)
{
	PM->AddScore(score);
}

void Frog::AddFood(Food* food)
{
	this->food = food;
	if (this->food != nullptr)
	{
		hasFood = true;
		this->food->AttachToPlayer();
		AddScore(100);
	}
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

void Frog::Render()
{
}
