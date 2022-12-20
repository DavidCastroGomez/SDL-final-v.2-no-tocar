#pragma once
#include "SDL.h"

#define LM LifeManager::GetInstance()

class LifeManager
{
public:

	int GetLives();
	void RemoveLife();
	static LifeManager* GetInstance();
private:
	static LifeManager* instance;
	int remainingLives;
	LifeManager(int maxLives);
};
