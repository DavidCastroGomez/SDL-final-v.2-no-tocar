#pragma once
#include <vector>
#include <SDL.h>

class Scene {
protected:
	//TODO ui and objects
public:
	virtual void Update(float dt) = 0;
	virtual void Render(SDL_Renderer*) = 0; //TODO erase renderer from render
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

};