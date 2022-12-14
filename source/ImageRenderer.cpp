#include "ImageRenderer.h"

ImageRenderer::ImageRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect* targetRect, SDL_Rect* sourceRect, SDL_Point center)
	: Renderer(color, alpha, position, rotation, scale, targetRect, sourceRect, center)
{
}

void ImageRenderer::Load(std::string path)
{
	//The final texture
	texture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	assert(loadedSurface != NULL);
	//Create texture from surface pixels
	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), loadedSurface);
	assert(texture != NULL);

	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
}


void ImageRenderer::Update()
{
	targetRect->x = position.x;
	targetRect->y = position.y;

	/*int newX, newY;

	SDL_GetWindowSize(RM->GetWindow(), &newX, &newY);

	scale.x = scale.x * (newX / RM->windowWidth);
	scale.y = scale.y * (newY / RM->windowHeight);*/

	//targetRect->w = sourceRect->x * scale.x;
	//targetRect->h = sourceRect->y * scale.y;
	SDL_SetTextureAlphaMod(texture, (Uint8)alpha);
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

void ImageRenderer::Render()
{
	SDL_RenderCopyEx(RM->GetRenderer(), texture, sourceRect, targetRect, rotation, &center, SDL_FLIP_NONE);
}
