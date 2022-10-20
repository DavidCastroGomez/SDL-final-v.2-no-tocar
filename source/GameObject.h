#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
class GameObject
{
public:
	SDL_Texture* texture;
	SDL_Rect destinationRect;
	SDL_Rect sourceRect;
	GameObject() = default;
	void LoadTexture(SDL_Renderer* renderer, std::string path);
	void SetPosition(int x, int y);
};

