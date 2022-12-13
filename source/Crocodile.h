#pragma once
#include <SDL_image.h>
#include "Log.h"
class Crocodile : private Log
{
public:
	Crocodile(float openMouthDuration, float closedMouthDuration, float elapsedTime, int length);
	void Update() override;
	void Render() override;
	bool IsMouthOpened();
private:
	float openMouthDuration, closedMouthDuration, elapsedTime;
};