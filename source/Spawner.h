#pragma once
#include "GameObject.h"
#include "Vector2.h"
class Spawner
{
public:
	Spawner<GameObject>(); //NI IDEA
	GameObject* Update();
private:
	float maxSpawnTime, minSpawnTime, elapsedTime;
	Vector2 startPosition, startVelocity;
};