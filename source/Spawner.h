#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Car.h"
#include "DivingTurtles.h"
#include "EndTileItem.h"
#include "Food.h"
#include "Frog.h"
#include "Log.h"
#include "Snake.h"
#include "Tile.h"
#include "Turtles.h"
#include "TimeManager.h"
#include "Crocodile.h"
#include <string>
class Spawner
{
public:
	Spawner(std::string id); //No fer templates

	std::vector<GameObject*>* Update();
	std::vector<GameObject*>* Spawn();

	void SetMaxSpawnTime(float f);
	void SetMinSpawnTime(float f);

	void SetMinLength(float f);
	void SetMaxLength(float f);

	void SetStartPosition(Vector2 pos);
	void SetStartVelocity(int vel);

	void SetVariantChance(int i);
	void SetSnakeChance(int i);
	void SetCarId(std::string id);
	void SetCanSpawn(bool b);

	void SetLastRow(bool b);
	void SetEndPositions(bool* b, int pos);

private:
	std::string id;
	std::string carId;
	int startVelocity;
	float maxSpawnTime, minSpawnTime, elapsedTime;
	int minLength, maxLength;
	Vector2 startPosition;

	int spawnVariantChance, spawnSnakeChance;
	bool canSpawnEnd;
	bool lastRow;
	bool* endPositions[5];

	GameObject* food;

};