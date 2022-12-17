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
		if (((rand() + (int)startPosition.y) % 2000) == 0) {
			return Spawn();
		}
	}

	return nullptr;
}

GameObject* Spawner::Spawn()
{

	if (id == "log") {
		int length;
		do {
			length = (rand() % maxLength) + 1;
		} while (length <= minLength);

		if (rand() % 100 < spawnVariantChance) {
			//Crocodile* croc
		}
		else {
			Log* log = new Log(length);
			log->SetPosition(startPosition);
			elapsedTime = 0.f;
			return log;
		}
	}
	else if (id == "turtle") {
		int length;
		do {
			length = (rand() % maxLength) + 1;
		} while (length < minLength);

		if (rand() % 1 < spawnVariantChance) {
			DivingTurtles* divingTurtles = new DivingTurtles(1.5,3);
			divingTurtles->SetPosition(startPosition);
			elapsedTime = 0.f;
			return divingTurtles;
		}
		else {
			Turtles* turtle = new Turtles();
			turtle->SetPosition(startPosition);
			elapsedTime = 0.f;
			return turtle;
		}
	}
	else if (id == "car") {
		Car* car = new Car(carId, startVelocity);
		car->SetPosition(startPosition);
		elapsedTime = 0.f;
		return car;
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

void Spawner::SetStartVelocity(int vel)
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

void Spawner::SetCarId(std::string id)
{
	this->carId = id;
}
