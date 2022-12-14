#pragma once
#include <SDL.h>

#define RM RendererManager::GetInstance()

class RendererManager
{
private:
	static RendererManager* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;

	RendererManager(int width, int heigth, Uint32 flags);

public:
	float windowWidth;
	float windowHeight;

	static RendererManager* GetInstance();
	SDL_Renderer* GetRenderer();
	void ClearScreen();
	void RenderScreen();
	SDL_Window* GetWindow();
};

