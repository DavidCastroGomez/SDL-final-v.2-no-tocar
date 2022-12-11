#pragma once
#include <SDL_image.h>
#include "Turtles.h"
class DivingTurtles : private Turtles
{
public:
	DivingTurtles(float diveDuration, float surfaceDuration, int length);
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
	bool isDiving();
private:
	float diveDuration, surfaceDuration, elapsedTime;
};