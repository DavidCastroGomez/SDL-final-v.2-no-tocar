#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "TimeManager.h"
class Log : public GameObject
{
public:
	Log(int length);
	virtual void Update() override;
	virtual void Render() override;
private:
	int length;
};