#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;

const float TimeManager::tick = 1/60.f;
float TimeManager::deltaTime = 0.f;
Uint64 TimeManager::end = 0;
Uint64 TimeManager::lastRenderTime = 0;
float TimeManager::totalTime = 0.f;

TimeManager* TimeManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new TimeManager();
        end = SDL_GetPerformanceCounter();
    }
    return instance;
}

void TimeManager::Update()
{
    deltaTime = (SDL_GetPerformanceCounter() - end) / (float)SDL_GetPerformanceFrequency();
    std::cout << deltaTime << std::endl;
    end = SDL_GetPerformanceCounter();
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
    if (end - lastRenderTime > tick) {
        lastRenderTime = end;
        return true;
    }
    return false;
}
