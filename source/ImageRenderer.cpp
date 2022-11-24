#include "ImageRenderer.h"

ImageRenderer::ImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect) 
	: Renderer(color, alpha, position, rotation, scale, targetRect, sourceRect)
{
}

void ImageRenderer::Load(std::string)
{
}

void ImageRenderer::Update()
{
}

void ImageRenderer::Render()
{
}
