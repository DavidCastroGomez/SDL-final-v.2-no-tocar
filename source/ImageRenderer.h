#pragma once
#include "Renderer.h"
class ImageRenderer : public Renderer
{
public:
	ImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, SDL_Point center);

	virtual void Load(std::string) override;

	virtual void Update() override;
	virtual void Render() override;
};

