#pragma once
#include <SDL_image.h>
#include "Turtles.h"
class DivingTurtles : public Turtles
{
public:
	DivingTurtles(float diveDuration, float surfaceDuration);
	void Update() override;
	void Render() override;
	bool IsDiving();
private:
	bool isDiving;
	float diveDuration, surfaceDuration, elapsedTime;
	int length;
};