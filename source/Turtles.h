#pragma once
#include <SDL_image.h>
#include "GameObject.h"
class Turtles : public GameObject
{
public:
	Turtles();
	virtual void Update() override;
	virtual void Render() override;
private:
	int length;
};