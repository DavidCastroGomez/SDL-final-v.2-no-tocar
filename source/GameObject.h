#pragma once
#include "Object.h"
#include "Renderer.h"
#include <SDL.h>
#include <string>
#include <SDL_image.h>

class GameObject : public Object
{
protected:
	//TODO std::vector<ImageRenderer> renderer; 

public:
	
	GameObject() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
	//TODO Renderer* GetRenderer();
};

