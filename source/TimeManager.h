#pragma once
#include <SDL.h>
#include <iostream>

#define TM TimeManager::GetInstance()

class TimeManager
{
private:
	static float deltaTime;
	static Uint64 end;
	static Uint64 lastRenderTime;
	static TimeManager* instance;

	TimeManager() = default;

public:
	static const float tick;
	static float totalTime;

	static TimeManager* GetInstance();
	void Update();
	float GetCurrentTime();
	float GetDeltaTime();
	bool ShouldRenderFrame();
};

