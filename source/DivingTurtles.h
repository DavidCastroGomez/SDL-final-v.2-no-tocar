#pragma once
#include <SDL_image.h>
#include "Turtles.h"
class DivingTurtles : private Turtles
{
public:
	DivingTurtles(float diveDuration, float surfaceDuration, int length);
	void Update() override;
	void Render() override;
	bool isDiving();
private:
	float diveDuration, surfaceDuration, elapsedTime;
};