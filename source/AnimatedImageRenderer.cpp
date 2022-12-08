#include "AnimatedImageRenderer.h"

AnimatedImageRenderer::AnimatedImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, 
	int frameWidth, int frameHeigth, int maxFrames, int frameTime, int cols, bool looping)
	: ImageRenderer(color, alpha, position, rotation, scale, targetRect, sourceRect)
{
	this->frameWidth = frameWidth;
	this->frameHeigth = frameHeigth;
	this->maxFrames = maxFrames;
	this->looping = looping;

	this->currentFrame = 0;
	this->frameTime = 1/frameTime;
	this->currentFrameTime = 0;

	this->cols = cols;
}

void AnimatedImageRenderer::Load(std::string path)
{
	ImageRenderer::Load(path);
}

void AnimatedImageRenderer::Update(float dt)
{
	ImageRenderer::Update(dt);

	currentFrameTime += dt;
	int frameIncrement = (int)(currentFrameTime / frameTime);

	currentFrameTime = ((currentFrameTime / frameTime) - (float)frameIncrement) * frameTime;

	currentFrame += frameIncrement;

	if (currentFrame >= maxFrames) {
		if (looping)
			currentFrame %= maxFrames;
		else
			currentFrame = maxFrames - 1;
	}

	int frameX = currentFrame % cols;
	int frameY = currentFrame / cols;

	sourceRect = { sourceRect.w * frameX, sourceRect.h * frameY, sourceRect.w, sourceRect.h };
}

void AnimatedImageRenderer::Render()
{
	ImageRenderer::Render();
}
