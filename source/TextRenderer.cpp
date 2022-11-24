#include "TextRenderer.h"

TextRenderer::TextRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, std::string text)
	: Renderer(color, alpha, position, rotation, scale, targetRect, sourceRect)
{
	this->text = text;
}

void TextRenderer::Load(std::string)
{
	//TODO this
}

void TextRenderer::Update()
{
}

void TextRenderer::Render()
{
}

std::string TextRenderer::GetText()
{
	return text;
}

void TextRenderer::SetText(std::string text)
{
	this->text = text;
}
