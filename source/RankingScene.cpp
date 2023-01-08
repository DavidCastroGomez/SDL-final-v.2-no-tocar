#include "RankingScene.h"

void RankingScene::Update()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}
	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Update();
	}
}

void RankingScene::Render()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Render();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Render();
	}

	if (IM->GetMouseX() <= 120 && IM->GetMouseX() >= 50)
	{
		if (IM->GetMouseY() >= 22 && IM->GetMouseY() <= 42)
		{
			SM->SetScene("Main Menu");
		}
	}
}

void RankingScene::OnEnter()
{
	AM->LoadMusic("ranking");
	AM->PlayMusic("ranking");

	TextObject* exitButton = new TextObject("BACK TO MENU", Vector2(60, 30));
	ui.push_back(exitButton);
}

void RankingScene::OnExit()
{
	AM->UnloadMusic("ranking");
}