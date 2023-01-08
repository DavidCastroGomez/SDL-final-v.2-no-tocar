#include "SplashSceneScene.h"

void SplashScreenScreen::Update()
{
	timer += TM->GetDeltaTime();
	if (IM->CheckKeyState(SDLK_SPACE, PRESSED) || timer >= 3.0f) {
		SM->SetScene("Main Menu");
	}
}

void SplashScreenScreen::Render()
{
	logo->Render();
}

void SplashScreenScreen::OnEnter()
{
	timer = 0.0f;

	SDL_Rect* source = new SDL_Rect();

	source->x = 0;
	source->y = 0;
	source->w = 225;
	source->h = 225;

	SDL_Rect* target = new SDL_Rect();

	target->x = 30;
	target->y = 50;
	target->w = 225 / 2;
	target->h = 225 / 2;

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = target->w / 2,
		center.y = target->h / 2,
	};

	logo = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
	logo->Load("./resources/logo.png");
}

void SplashScreenScreen::OnExit()
{

}
