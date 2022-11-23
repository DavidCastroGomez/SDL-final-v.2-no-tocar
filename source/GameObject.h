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
	virtual void Update() override = 0;
	virtual void Render() override = 0;
	//TODO Renderer* GetRenderer();
};

