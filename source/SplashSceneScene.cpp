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
}

void SplashScreenScreen::OnEnter()
{
	timer = 0.0f;
}

void SplashScreenScreen::OnExit()
{
	
}
