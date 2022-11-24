#pragma once
#include "ImageRenderer.h"
class AnimatedImageRenderer :
    public ImageRenderer
{
private:
    int frameWidth;
    int frameHeigth;
    int fps;
    bool looping;
    float frameTime;
    float currentFrameTime;

public:
    AnimatedImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect,
        int frameWidth, int frameHeigth, int fps, bool looping);

    void Load(std::string) override;

    void Update() override;
    void Render() override;
};

