#include "TimeManager.h"

const float TimeManager::FPS = 60.f;
const float TimeManager::tick = 1/60.f;

TimeManager* TimeManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new TimeManager();
    }

    return instance;
}

void TimeManager::Update()
{
    //TODO TimeManager::Update()
}

float TimeManager::GetCurrentTime()
{
    //TODO What time?
    return 0.0f;
}

float TimeManager::GetDeltaTime()
{
    return deltaTime;
}
