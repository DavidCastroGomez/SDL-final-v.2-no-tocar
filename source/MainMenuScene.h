#pragma once
#include <iostream>
#include "Scene.h"

class MainMenuScene : public Scene {
	// Inherited via Scene
	virtual void Update(float dt) override;
	virtual void Render() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};