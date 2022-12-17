#include "AnimatedImageRenderer.h"

AnimatedImageRenderer::AnimatedImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect* targetRect, SDL_Rect* sourceRect, SDL_Point center,
	int frameWidth, int frameHeigth, int maxFrames, float frameTime, int cols, bool looping)
	: ImageRenderer(color, alpha, position, rotation, scale, targetRect, sourceRect, center)
{
	this->frameWidth = frameWidth;
	this->frameHeigth = frameHeigth;
	this->maxFrames = maxFrames;
	this->looping = looping;

	this->frameTime = frameTime;

	this->currentFrame = 0;
	this->currentFrameTime = 0;

	this->cols = cols;

	this->initialX = sourceRect->x;
	this->initialY = sourceRect->y;
}

void AnimatedImageRenderer::Load(std::string path)
{
	ImageRenderer::Load(path);
}

void AnimatedImageRenderer::Update()
{
	ImageRenderer::Update();

	currentFrameTime += TM->GetDeltaTime();
	int frameIncrement = (int)(currentFrameTime / frameTime);

	currentFrameTime = ((currentFrameTime / frameTime) - (float)frameIncrement) * frameTime;

	//std::cout << currentFrameTime << std::endl;

	currentFrame += frameIncrement;

	if (currentFrame >= maxFrames) {
		if (looping)
			currentFrame = 0;
		else
			currentFrame = maxFrames - 1;
	}

	int frameX = currentFrame % cols;
	int frameY = currentFrame / cols;

	sourceRect->x = initialX + sourceRect->w * frameX;
	sourceRect->y = initialY + sourceRect->h * frameY;
}

void AnimatedImageRenderer::Render()
{
	ImageRenderer::Render();
}
