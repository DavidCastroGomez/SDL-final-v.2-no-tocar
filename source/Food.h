#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Log.h"
#include "Frog.h"
class Food : public GameObject
{
public:
	Food(Log* log);
	void Update() override;
	void Render() override;
	void AttachToPlayer(Frog* frog);
private:
	Log* log;
	Frog* frog;
	bool attachedToPlayer;
	bool isMoving;
};