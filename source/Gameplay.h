#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Spawner.h"
#include "GameObject.h"
#include "Frog.h"
#include "Scene.h"
class Gameplay : public Scene
{
public:
	Spawner spawners;
	std::vector <GameObject> tiles;
	bool endPositions[5];
	Frog player;
	static int level;
	int score;

	Gameplay() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
private:
	void SaveScore();
	void LoadLevelFromFile(std::string path);
};