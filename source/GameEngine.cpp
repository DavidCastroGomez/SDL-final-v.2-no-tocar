#include "GameEngine.h"
#include <random>

GameEngine::GameEngine(int x, int y) {
	windowWidth = x;
	windowHeight = y;
	isRunning = true;
}

#pragma region INITIALIZATION
void GameEngine::Init() {
	//Initialize SDL
	InitSDL();
	//Create a window and a renderer
	InitWindowAndRenderer();

	logo.LoadTexture(renderer, "resources/logo.png");

}

void GameEngine::InitSDL() {
	int result = SDL_Init(SDL_INIT_VIDEO);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}

void GameEngine::InitWindowAndRenderer() {

	int result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &window, &renderer);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}


#pragma endregion INITIALIZATION

void GameEngine::Quit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameEngine::Render()
{
	//Set the clear color for the renderer
	SDL_SetRenderDrawColor(renderer, rand(), rand(), rand(), rand());
	//Renderer the background
	SDL_RenderClear(renderer);
	//Gameobjects
	SDL_RenderCopy(renderer, logo.texture, &logo.sourceRect, &logo.destinationRect);
	//UI
	SDL_RenderPresent(renderer);
}



void GameEngine::Run() {
	srand(time(NULL));
	while (isRunning) {
		//HandleEvents();
		IM.Listen();
		isRunning = !IM.GetQuitEvent();
		//Update();

		//Render();
		Render();

		logo.SetPosition(rand() % 500, rand() % 500);
	}
}