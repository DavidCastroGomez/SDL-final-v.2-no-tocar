#pragma once
#include "Object.h"
#include <SDL.h>
#include <string>
#include <SDL_image.h>

class GameObject : public Object
{
protected:
	//TODO std::vector<ImageRenderer> renderer; 

public:
	
	GameObject() = default;
	virtual void Update(float dt) = 0;
	virtual void Render(SDL_Renderer*) = 0;
	//TODO Renderer* GetRenderer();
};

