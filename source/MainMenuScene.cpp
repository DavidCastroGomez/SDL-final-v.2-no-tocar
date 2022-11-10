#include "MainMenuScene.h"

void MainMenuScene::Update(float dt)
{

	//Cjeck if the mouse is inside the render rect
	int width = 28 * sampleText.text.length();
	int heigth = 50;
	//sampletext.position <- x,y

	int x = sampleText.position[0] - width / 2;
	int y = sampleText.position[1] - heigth / 2;

	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > x && mouseX < x + width;
	bool isInsideAABBY = mouseY > y && mouseY < y + heigth;

	if (isInsideAABBX && isInsideAABBY) {
		buttonAngle += 0.002f;
		if (IM->CheckKeyState(SDLK_k, PRESSED)) {
			SM->SetScene("Splash Screen");
		}
	}
	else {
		buttonAngle = 0;
	}
}

void MainMenuScene::Render(SDL_Renderer* renderer)
{
	//TextData (esto no va aqui)

	int width = 28 * sampleText.text.length();
	int heigth = 50;

	SDL_Color color = { 0, 0, 0 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, sampleText.text.c_str(), color);

	assert(surface != nullptr);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	assert(texture != nullptr);

	SDL_SetTextureAlphaMod(texture, 255);

	SDL_Rect renderRect =
	{
		sampleText.position[0] - width/2,
		sampleText.position[1] - heigth/2,
		width,
		heigth
	};
		   //RENDERER,  TARGETTEXTURE,       TEXTURE PART WE WANT TO DRAW, ANGLE,	CENTRO,		FLIP?
	SDL_RenderCopyEx(renderer, texture, NULL, &renderRect, sin(buttonAngle) * 30, NULL, SDL_FLIP_NONE);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);	
}

void MainMenuScene::OnEnter()
{
	assert(TTF_Init() != -1);

	font = TTF_OpenFont("resources/fonts/hyperspace.ttf", 28);
	assert(font != nullptr);

	sampleText.text = "HOLA!";

	sampleText.position[0] = 250;
	sampleText.position[1] = 250;

	buttonAngle = 0;
}

void MainMenuScene::OnExit()
{
}
