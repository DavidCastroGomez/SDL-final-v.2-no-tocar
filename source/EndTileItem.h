#pragma once
#include <string>
#include <SDL_image.h>
#include "Spawner.h"
#include "GameObject.h"
#include "ColliderManager.h"

class Spawner;

class EndTileItem : public GameObject
{
public:
	EndTileItem(float duration, bool isLethal, Spawner* spawner);
	void Update() override;
	void Render() override;
	bool IsFinished();
private:
	Spawner* spawner;
	float duration, currentDuration;
	bool isLethal, isFinished;
};