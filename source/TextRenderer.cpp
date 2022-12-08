#include "TextRenderer.h"

TextRenderer::TextRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, std::string text)
	: Renderer(color, alpha, position, rotation, scale, targetRect, sourceRect)
{
	this->text = text;
}

void TextRenderer::Load(std::string path)
{
	assert(TTF_Init() != -1);

	TTF_Font* font = TTF_OpenFont(path.c_str(), 28);
	assert(font != nullptr);

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);

	assert(surface != nullptr);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);

	assert(texture != nullptr);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void TextRenderer::Update(float)
{
	targetRect.x = (int)position.x;
	targetRect.y = (int)position.y;
	targetRect.w = (int)sourceRect.x * (int)scale.x;
	targetRect.h = (int)sourceRect.y * (int)scale.y;
	SDL_SetTextureAlphaMod(texture, (Uint8)alpha);
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

void TextRenderer::Render()
{
	SDL_RenderCopyEx(RM->GetRenderer(), texture, &sourceRect, &targetRect, rotation, NULL, SDL_FLIP_NONE);
}

std::string TextRenderer::GetText()
{
	return text;
}

void TextRenderer::SetText(std::string text)
{
	this->text = text;
}
