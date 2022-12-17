#include "Crocodile.h"

Crocodile::Crocodile(float openMouthDuration, float closedMouthDuration, float elapsedTime)
{
	this->openMouthDuration = openMouthDuration;
	this->closedMouthDuration = closedMouthDuration;
	this->elapsedTime = elapsedTime;
	isMouthOpen = false;
}

void Crocodile::Update()
{
	if (TM->GetCurrentTime() - TM->GetDeltaTime() > openMouthDuration && IsMouthOpen())
	{
		isMouthOpen = false;
	}
	else if (TM->GetCurrentTime() - TM->GetDeltaTime() > closedMouthDuration && !IsMouthOpen())
	{
		isMouthOpen = true;
	}
	transform.position.x += 8 * TM->GetDeltaTime();
}

void Crocodile::Render()
{
}

bool Crocodile::IsMouthOpen()
{
	return isMouthOpen;
}