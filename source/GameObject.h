#pragma once
#include "Object.h"
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "ImageRenderer.h"
#include "AnimatedImageRenderer.h"

class GameObject : public Object
{
public:
	
	GameObject() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
	//TODO Renderer* GetRenderer();
};

