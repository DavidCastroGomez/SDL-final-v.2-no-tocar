#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Log.h"
class Snake : public GameObject
{
public:
	Snake(Log* log);
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
private:
	Log* log;
};