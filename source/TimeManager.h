#pragma once
class TimeManager
{
private:
	float deltaTime;
	TimeManager* instance;

	TimeManager() = default;

public:
	static const float FPS;
	static const float tick;

	TimeManager* GetInstance();
	void Update();
	float GetCurrentTime();
	float GetDeltaTime();
};

