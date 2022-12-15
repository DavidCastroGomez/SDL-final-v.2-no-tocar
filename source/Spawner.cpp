#include "Spawner.h"

Spawner::Spawner(std::string id)
{
	this->id = id;
	this->elapsedTime = 0.f;
}

GameObject* Spawner::Update()
{
	elapsedTime += TM->GetDeltaTime();
	if (elapsedTime >= maxSpawnTime) {
		return Spawn();
	}

	if (elapsedTime > minSpawnTime) {
		if (rand() % 3 > elapsedTime) {
			return Spawn();
		}
	}

	return nullptr;
}

GameObject* Spawner::Spawn()
{
	if (id == "log") {
		if (rand() % 100 < spawnVariantChance) {
			//summon croc
		}
		else {
			//summon log
		}
	}
	else if (id == "turtle") {
		if (rand() % 100 < spawnVariantChance) {
			//summon diveturt
		}
		else {
			//summon turt
		}
	}
	else if (id == "car") {
		//carShit
	}
	return nullptr;
}

void Spawner::SetMaxSpawnTime(float f)
{
	this->maxSpawnTime = f;
}

void Spawner::SetMinSpawnTime(float f)
{
	this->minSpawnTime = f;
}

void Spawner::SetMinLength(float f)
{
	this->minLength = f;
}

void Spawner::SetMaxLength(float f)
{
	this->maxLength = f;
}

void Spawner::SetStartPosition(Vector2 pos)
{
	this->startPosition = pos;
}

void Spawner::SetStartVelocity(Vector2 vel)
{
	this->startVelocity = vel;
}

void Spawner::SetVariantChance(int i)
{
	this->spawnVariantChance = i;
}

void Spawner::SetSnakeChance(int i)
{
	this->spawnSnakeChance = i;
}
