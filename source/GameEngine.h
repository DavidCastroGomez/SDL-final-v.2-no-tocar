#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SplashSceneScene.h"
#include "MainMenuScene.h"
#include "GameplayScene.h"

class GameEngine
{
private:
	bool isRunning;

public:
	GameEngine();
	void Init();
	void Run();
	void Quit();
};

