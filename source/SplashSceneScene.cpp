#include "SplashSceneScene.h"

void SplashScreenScreen::Update()
{
	if (IM->CheckKeyState(SDLK_SPACE, PRESSED)) {
		SM->SetScene("Main Menu");
	}
}

void SplashScreenScreen::Render()
{
}

void SplashScreenScreen::OnEnter()
{
	std::cout << "Hola :D";
}

void SplashScreenScreen::OnExit()
{
	std::cout << "Adios :c";
}
