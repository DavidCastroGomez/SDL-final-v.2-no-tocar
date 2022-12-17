#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;

const float TimeManager::tick = 1/60.f;
float TimeManager::lastDeltaTime = 0.f;
float TimeManager::lastRenderTime = 0.f;
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
    deltaTime = (float)(SDL_GetPerformanceCounter() - lastDeltaTime) / SDL_GetPerformanceFrequency();
    lastDeltaTime = SDL_GetPerformanceCounter();
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

bool TimeManager::ShouldRenderFrame() {
    if (lastDeltaTime - lastRenderTime > tick) {
        lastRenderTime = lastDeltaTime;
        return true;
    }
    return false;
}
