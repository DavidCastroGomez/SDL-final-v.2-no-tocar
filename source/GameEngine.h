#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SplashSceneScene.h"
#include "MainMenuScene.h"

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

	void Render();

public:
	GameEngine(int x, int y);
	void Init();
	void Run();
	void Quit();
};

