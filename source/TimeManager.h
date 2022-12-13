#pragma once
#include <SDL.h>
#include <iostream>

#define TM TimeManager::GetInstance()

class TimeManager
{
private:
	float deltaTime;
	static float lastDeltaTime;
	static TimeManager* instance;

	TimeManager() = default;

public:
	static const float FPS;
	static const float tick;
	static float totalTime;

	static TimeManager* GetInstance();
	void Update();
	float GetCurrentTime();
	float GetDeltaTime();
};

