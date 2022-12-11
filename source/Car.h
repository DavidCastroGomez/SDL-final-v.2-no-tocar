#pragma once
#include <string>
#include <SDL_image.h>
#include "GameObject.h"
class Car : public GameObject
{
public:
	Car(std::string spritePath);
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
private:
	std::string spritePath;
};