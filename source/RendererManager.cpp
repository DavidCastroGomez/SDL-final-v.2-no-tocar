#include "RendererManager.h"

RendererManager* RendererManager::instance = nullptr;

RendererManager::RendererManager(int width, int heigth, Uint32 flags)
{
	windowWidth = width;
	windowHeight = heigth;

	int result = SDL_Init(SDL_INIT_VIDEO);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();

	result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, flags, &window, &renderer);

	success = result >= 0;
	if (!success)
		throw SDL_GetError();
}

RendererManager* RendererManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new RendererManager(176, 240, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
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

SDL_Window* RendererManager::GetWindow()
{
	return window;
}

