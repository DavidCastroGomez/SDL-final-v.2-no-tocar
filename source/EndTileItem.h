#pragma once
#include <string>
#include <SDL_image.h>
#include "GameObject.h"
class EndTileItem : public GameObject
{
public:
	EndTileItem(float duration, bool isLethal);
	void Update() override;
	void Render() override;
	bool IsFinished();
private:
	float duration, currentDuration;
	bool isLethal, isFinished;
};