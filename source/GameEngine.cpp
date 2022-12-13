#include "GameEngine.h"
#include <random>

GameEngine::GameEngine() {
	isRunning = true;
}

#pragma region INITIALIZATION
void GameEngine::Init() {
	SM;
	TM;
	RM;

	GameplayScene* gameS = new GameplayScene();

	SM->AddScene("Game", gameS);
	SM->SetScene("Game");
}


#pragma endregion INITIALIZATION

void GameEngine::Quit() {
	SDL_DestroyRenderer(RM->GetRenderer());
	//SDL_DestroyWindow(RM);
	SDL_Quit();
}

//void GameEngine::Render()
//{
//	//Set the clear color for the renderer
//	
//	//Renderer the background
//	SDL_RenderClear(renderer);
//	//Gameobjects
//	SDL_RenderCopy(renderer, logo.texture, &logo.sourceRect, &logo.destinationRect);
//	//UI
//	SDL_RenderPresent(renderer);
//}



void GameEngine::Run() {
	//Before game loop
	//{
	//	SplashScreenScreen* s3 = new SplashScreenScreen();
	//	MainMenuScene* mms = new MainMenuScene();
	//	SM->AddScene("Splash Screen", s3);
	//	SM->AddScene("Main Menu", mms);
	//	SM->SetScene("Splash Screen");
	//}

	//srand(time(NULL));
	//while (isRunning) {
	//	//HandleEvents();
	//	IM->Listen();
	//	isRunning = !IM->GetQuitEvent();
	//	SM->GetCurrentScene()->Update(0.0f);
	//	SDL_SetRenderDrawColor(renderer, 230, 100, 100, 255);
	//	SDL_RenderClear(renderer);
	//	SM->GetCurrentScene()->Render(renderer);

	//	SDL_RenderPresent(renderer);
	//}



	while (isRunning) {
		IM->Listen();
		isRunning = !IM->GetQuitEvent();

		TM->Update();
		SM->GetCurrentScene()->Update();

		SDL_SetRenderDrawColor(RM->GetRenderer(), 255, 255, 255, 255);

		SDL_RenderClear(RM->GetRenderer());

		SM->GetCurrentScene()->Render();
		RM->RenderScreen();

	}

}