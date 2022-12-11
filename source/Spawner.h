#pragma once
#include "Vector2.h"
class Spawner
{
public:
	//TODO
	//Spawner<ObjectType>();
	//ObjectType* Update();
private:
	float maxSpawnTime, minSpawnTime, elapsedTime;
	Vector2 startPosition, startVelocity;
};