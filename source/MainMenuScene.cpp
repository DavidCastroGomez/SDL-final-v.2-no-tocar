#include "MainMenuScene.h"

void MainMenuScene::Update()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Update();
	}

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

}

void MainMenuScene::OnExit()
{
}
