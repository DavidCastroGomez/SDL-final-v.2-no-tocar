#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;

const float TimeManager::FPS = 60.f;
const float TimeManager::tick = 1/60.f;
float TimeManager::lastDeltaTime = 0.f;
float TimeManager::totalTime = 0.f;

TimeManager* TimeManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new TimeManager();
    }

    return instance;
}

void TimeManager::Update()
{
    deltaTime = (SDL_GetTicks() - lastDeltaTime) * (FPS / 1000.0f);
    if (deltaTime > tick)
        deltaTime = tick;
    lastDeltaTime = deltaTime - SDL_GetTicks();
    totalTime += deltaTime;
}

float TimeManager::GetCurrentTime()
{
    return totalTime;
}

float TimeManager::GetDeltaTime()
{
    return deltaTime;
}
