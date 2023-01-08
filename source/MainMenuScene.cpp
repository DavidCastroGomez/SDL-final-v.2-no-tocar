#include "MainMenuScene.h"

void MainMenuScene::Update()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Update();
	}

	//No se com definir l'event SDL_MOUSEBUTTONDOWN
	if (true)
	{
		//PLAY
		if (IM->GetMouseX() <= 120 && IM->GetMouseX() >= 50)
		{
			if (IM->GetMouseY() <= RM->windowHeight - 132 && IM->GetMouseY() >= RM->windowHeight - 152)
				SM->SetScene("Gameplay");
		}
		//RANKING
		if (IM->GetMouseX() <= 120 && IM->GetMouseX() >= 50)
		{
			if (IM->GetMouseY() <= RM->windowHeight - 102 && IM->GetMouseY() >= RM->windowHeight - 122)
				SM->SetScene("Ranking");
		}
		//MUTE
		if (IM->GetMouseX() <= 120 && IM->GetMouseX() >= 50)
		{
			if (IM->GetMouseY() <= RM->windowHeight - 52 && IM->GetMouseY() >= RM->windowHeight - 92)
				AM->SetMuted(!AM->GetMuted());
		}
		//EXIT
		if (IM->GetMouseX() <= 120 && IM->GetMouseX() >= 50)
		{
			if (IM->GetMouseY() <= RM->windowHeight - 42 && IM->GetMouseY() >= RM->windowHeight - 62)
			{
				OnExit();
				SDL_Quit();
				return;
			}
		}
	}

	std::cout << "MouseX: " << IM->GetMouseX() << std::endl << "MouseY: " << IM->GetMouseY() << std::endl;
}

void MainMenuScene::Render()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Render();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Render();
	}
}

void MainMenuScene::OnEnter()
{
	AM->LoadMusic("menu");
	AM->PlayMusic("menu");

	TextObject* playButton = new TextObject("PLAY GAME", Vector2(60, RM->windowHeight - 150));
	ui.push_back(playButton);
	TextObject* rankButton = new TextObject("SCORE RANKING", Vector2(60, RM->windowHeight - 120));
	ui.push_back(rankButton);
	TextObject* muteButton = new TextObject("MUTE SOUND", Vector2(60, RM->windowHeight - 90));
	ui.push_back(muteButton);
	TextObject* exitButton = new TextObject("EXIT GAME", Vector2(60, RM->windowHeight - 60));
	ui.push_back(exitButton);
}

void MainMenuScene::OnExit()
{
	AM->UnloadMusic("menu");
}
