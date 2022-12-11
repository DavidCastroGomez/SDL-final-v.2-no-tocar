#pragma once
#include <SDL_image.h>
#include "GameObject.h"
class Log : public GameObject
{
public:
	Log(int length);
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
private:
	int length;
};