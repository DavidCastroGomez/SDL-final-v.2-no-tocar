#pragma once
#include "ImageRenderer.h"
class AnimatedImageRenderer :
    public ImageRenderer
{
private:
    int frameWidth;
    int frameHeigth;
    int maxFrames;
    int currentFrame;
    bool looping;
    float frameTime;
    float currentFrameTime;
    int cols;


public:
    AnimatedImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect,
        int frameWidth, int frameHeigth, int maxFrames, int frameTime, int cols, bool looping);

    void Load(std::string) override;

    void Update(float) override;
    void Render() override;
};

