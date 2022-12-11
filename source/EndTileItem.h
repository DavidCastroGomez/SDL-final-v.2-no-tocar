#pragma once
#include <string>
#include <SDL_image.h>
#include "GameObject.h"
class EndTileItem : public GameObject
{
public:
	EndTileItem(float duration, bool isLethal, std::string spritePath);
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
	bool IsFinished();
private:
	float duration, currentDuration;
	bool isLethal, isFinished;
	std::string spritePath;
};