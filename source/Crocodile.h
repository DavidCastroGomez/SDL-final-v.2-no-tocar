#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "TimeManager.h"
class Crocodile : public GameObject
{
public:
	Crocodile(float openMouthDuration, float closedMouthDuration, float elapsedTime);
	void Update() override;
	void Render() override;
	bool IsMouthOpened();
private:
	float openMouthDuration, closedMouthDuration, elapsedTime;
	bool isMouthOpen;
};