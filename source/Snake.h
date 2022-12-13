#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Log.h"
class Snake : public GameObject
{
public:
	Snake(Log* log);
	void Update() override;
	void Render() override;
private:
	Log* log;
};