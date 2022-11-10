#pragma once
#include "SDL_ttf.h"
#include <assert.h>
#include "Scene.h"
#include "UIText.h"
#include "InputManager.h"
#include <cmath>
#include "SceneManager.h"

class MainMenuScene : public Scene {
private:
	UIText sampleText;
	TTF_Font* font;
	float buttonAngle;

public:	// Inherited via Scene
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};