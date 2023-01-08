#pragma once
#include <SDL.h>
#include <random>
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SplashSceneScene.h"
#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "EventsHandler.h"
#include "AudioManager.h"

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

