#pragma once

class Scene {
public:
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

};