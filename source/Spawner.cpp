#include "Spawner.h"

Spawner::Spawner(std::string id)
{
	this->id = id;
	this->elapsedTime = 0.f;
}

std::vector<GameObject*>* Spawner::Update()
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

std::vector<GameObject*>* Spawner::Spawn()
{
	std::vector<GameObject*>* spawned = new std::vector<GameObject*>;

	if (id == "log") {
		int length;
		do {
			length = (rand() % maxLength) + 1;
		} while (length < minLength);

		if (rand() % 100 < spawnVariantChance) {
			Crocodile* croc = new Crocodile(1, 1);
			croc->SetPosition(startPosition);
			spawned->push_back(croc);
		}
		else {
			Log* log = new Log(length);
			log->SetPosition(startPosition);
			spawned->push_back(log);
		}
	}
	else if (id == "turtle") {
		int length;
		do {
			length = (rand() % maxLength) + 1;
		} while (length < minLength);

		if (rand() % 100 < spawnVariantChance) {
			for (int i = 0; i < length; i++) {
				DivingTurtles* divingTurtles = new DivingTurtles(1.5, 3);
				Vector2 newStartPos(startPosition.x + i * 16, startPosition.y);
				divingTurtles->SetPosition(newStartPos);
				spawned->push_back(divingTurtles);
			}

		}
		else {
			for (int i = 0; i < length; i++) {
				Turtles* turtle = new Turtles();
				Vector2 newStartPos(startPosition.x + i * 16, startPosition.y);
				turtle->SetPosition(newStartPos);
				spawned->push_back(turtle);
			}
		}
	}
	else if (id == "car") {
		Car* car = new Car(carId, startVelocity);
		car->SetPosition(startPosition);
		spawned->push_back(car);
	}

	elapsedTime = 0.f;
	return spawned;
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
