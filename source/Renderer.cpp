#include "Renderer.h"

Renderer::Renderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, SDL_Point center)
{
	this->color = color;
	this->alpha = alpha;

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	this->targetRect = targetRect;
	this->sourceRect = sourceRect;

	this->center = center;
}

void Renderer::SetColor(SDL_Color color)
{
	this->color = color;
}

void Renderer::SetAlpha(float alpha)
{
	this->alpha = alpha;
}

void Renderer::SetPosition(Vector2 position)
{
	this->position = position;
}

void Renderer::SetRotation(float rotation)
{
	this->rotation = rotation;
}

void Renderer::SetScale(Vector2 scale)
{
	this->scale = scale;
}

SDL_Color Renderer::GetColor()
{
	return color;
}

float Renderer::GetAlpha()
{
	return alpha;
}
