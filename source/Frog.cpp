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
	hasFood = true;
	this->food->AttachToPlayer();
}

void Frog::Update()
{
	//Funcions que he de recordar mentre ho faig
	TM->GetDeltaTime();
	IM->CheckKeyState(SDLK_w, PRESSED);
	Transform(Transform().position, Transform().rotation, Transform().scale);
	transform.position = transform.position;

	if (IM->CheckKeyState(SDLK_w, PRESSED))
	{
		transform.position.y += 16;
	}
	if (IM->CheckKeyState(SDLK_s, PRESSED))
	{
		transform.position.y -= 16;
	}
	if (IM->CheckKeyState(SDLK_d, PRESSED))
	{
		transform.position.x += 16;
	}
	if (IM->CheckKeyState(SDLK_a, PRESSED))
	{
		transform.position.x -= 16;
	}
}