#include "AnimatedImageRenderer.h"

AnimatedImageRenderer::AnimatedImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, 
	int frameWidth, int frameHeigth, int fps, bool looping)
	: ImageRenderer(color, alpha, position, rotation, scale, targetRect, sourceRect)
{
	this->frameWidth = frameWidth;
	this->frameHeigth = frameHeigth;
	this->fps = fps;
	this->looping = looping;

	this->frameTime = 0;
	this->currentFrameTime = 0;
}

void AnimatedImageRenderer::Load(std::string)
{
}

void AnimatedImageRenderer::Update()
{
}

void AnimatedImageRenderer::Render()
{
}
