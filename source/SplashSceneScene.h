#pragma once
#include "Scene.h"
#include <iostream>
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "ImageRenderer.h"

class SplashScreenScreen : public Scene {
	// Inherited via Scene
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	float timer;
	ImageRenderer* logo;
};