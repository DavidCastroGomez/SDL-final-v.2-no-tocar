#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "InputManager.h"

class GameEngine
{
private:
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;

	int windowWidth;
	int windowHeight;

	void InitSDL();
	void InitWindowAndRenderer();

	InputManager IM;

	void Render();

	GameObject logo;

public:
	GameEngine(int x, int y);
	void Init();
	void Run();
	void Quit();
};

