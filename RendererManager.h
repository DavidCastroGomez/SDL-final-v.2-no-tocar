#pragma once
#include <SDL.h>

#define RM RendererManager::GetInstance()

class RendererManager
{
private:
	RendererManager* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;

	RendererManager(int width, int heigth, int flags);

public:
	float windowWidth;
	float windowHeight;

	RendererManager* GetInstance();
	SDL_Renderer* GetRenderer();
	void ClearScreen();
	void RenderScreen();
};

