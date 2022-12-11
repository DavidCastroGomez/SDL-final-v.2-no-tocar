#pragma once

#define TM TimeManager::GetInstance()

class TimeManager
{
private:
	float deltaTime;
	static TimeManager* instance;

	TimeManager() = default;

public:
	static const float FPS;
	static const float tick;

	static TimeManager* GetInstance();
	void Update();
	float GetCurrentTime();
	float GetDeltaTime();
};

