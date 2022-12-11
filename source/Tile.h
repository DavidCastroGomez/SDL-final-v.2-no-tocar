#pragma once
#include <SDL.h>
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile(bool isLethal);
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
private:
	bool isLethal;
};