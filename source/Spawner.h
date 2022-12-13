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
class Spawner
{
public:
	Spawner(); //No fer templates
	void Update();
private:
	float maxSpawnTime, minSpawnTime, elapsedTime;
	Vector2 startPosition, startVelocity;
};