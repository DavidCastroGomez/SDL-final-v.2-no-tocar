#pragma once
#include "Object.h"
#include <vector>
#include <SDL.h>
#include "RendererManager.h"

class Scene {
protected:
	std::vector<Object> ui;
	std::vector<Object> objects;
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

};