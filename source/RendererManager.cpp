#include "RendererManager.h"

RendererManager* RendererManager::instance = nullptr;

RendererManager::RendererManager(int width, int heigth, int flags)
{
	windowWidth = width;
	windowHeight = heigth;

	int result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, flags, &window, &renderer);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}

RendererManager* RendererManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new RendererManager(224, 240, SDL_WINDOW_RESIZABLE || SDL_WINDOW_SHOWN);
	}
	return instance;
}

SDL_Renderer* RendererManager::GetRenderer()
{
    return renderer;
}

void RendererManager::ClearScreen()
{
	SDL_RenderClear(renderer);
}

void RendererManager::RenderScreen()
{
	SDL_RenderPresent(renderer);
}
