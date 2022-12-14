#include "Spawner.h"

Spawner::Spawner(std::string id)
{
	this->id = id;
	this->elapsedTime = 0.f;

	this->lastRow = false;
	this->canSpawnEnd = true;

	this->food = nullptr;
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

		if (rand() % 99 < spawnVariantChance) {
			Crocodile* croc = new Crocodile(1, 1);
			croc->SetPosition(startPosition);
			spawned->push_back(croc);
		}
		else {
			Log* log = new Log(length);
			log->SetPosition(startPosition);
			spawned->push_back(log);

			if (rand() % 99 < spawnSnakeChance) {
				Snake* snake = new Snake(log);
				snake->SetPosition(startPosition);
				spawned->push_back(snake);
			}
			else {
				if (food == nullptr && lastRow) {
					food = new Food(log);
					food->SetPosition(startPosition);
					spawned->push_back(food);
				}
			}
		}
	}
	else if (id == "turtle") {
		int length;
		do {
			length = (rand() % maxLength) + 1;
		} while (length < minLength);

		if (rand() % 99 < spawnVariantChance) {
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
	else if (id == "end" && canSpawnEnd) {
		canSpawnEnd = false;
		int i = 0;
		do {
			i = rand() % 5;
		} while (!&endPositions[i]);

		Vector2 pos = Vector2(startPosition.x + i * 32, startPosition.y);
		if (rand() % 100 < spawnVariantChance) {
			EndTileItem* endItem = new EndTileItem(1, true, this);
			endItem->SetPosition(pos);
			spawned->push_back(endItem);
		}
		else {
			EndTileItem* endItem = new EndTileItem(5, false, this);
			endItem->SetPosition(pos);
			spawned->push_back(endItem);
		}
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

void Spawner::SetCanSpawn(bool b)
{
	canSpawnEnd = b;
	if (canSpawnEnd) {
		elapsedTime = 0;
	}
}

void Spawner::SetLastRow(bool b)
{
	lastRow = b;
}

void Spawner::SetEndPositions(bool* b, int pos)
{
	this->endPositions[pos] = b;
}


