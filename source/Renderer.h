#pragma once
#include "RendererManager.h"
#include <SDL_image.h>
#include "Vector2.h"
#include <string>
#include <assert.h>

class Renderer
{
protected:
	SDL_Texture* texture;
	SDL_Color color;
	float alpha;
	Vector2 position;
	float rotation;
	Vector2 scale;
	SDL_Rect targetRect;
	SDL_Rect sourceRect;

public:
	Renderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect);

	virtual void Load(std::string) = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;

	void SetColor(SDL_Color);
	void SetAlpha(float);
	void SetPosition(Vector2);
	void SetRotation(float);
	void SetScale(Vector2);

	SDL_Color GetColor();
	float GetAlpha();
};

