#pragma once
#include <SDL_image.h>
#include "GameObject.h"
class Turtles : public GameObject
{
public:
	Turtles(int length);
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
private:
	int length;
};