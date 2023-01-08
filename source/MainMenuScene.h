#pragma once
#include "SDL_ttf.h"
#include <assert.h>
#include "Scene.h"
#include "UIText.h"
#include "InputManager.h"
#include <cmath>
#include "SceneManager.h"
#include "AudioManager.h"
#include "TextObject.h"
#include "EventsHandler.h"

class MainMenuScene : public Scene {

public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};