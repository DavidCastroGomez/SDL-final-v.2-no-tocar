#include "LifeManager.h"

LifeManager* LifeManager::instance = nullptr;

LifeManager::LifeManager(int maxLives)
{
	remainingLives = maxLives;
}

LifeManager* LifeManager::GetInstance()
{
	if (instance == nullptr)
		instance = new LifeManager(0);
	return instance;
}

int LifeManager::GetLives()
{
	return remainingLives;
}

void LifeManager::RemoveLife()
{
	this->remainingLives--;
	if (remainingLives <= 0)
	{
		//End Game
	}
}