#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Log.h"
class Food : public GameObject
{
public:
	Food(Log* log);
	void Update() override;
	void Render() override;
	void AttachToPlayer();
private:
	Log* log;
	bool attachedToPlayer;
};