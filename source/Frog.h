#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Vector2.h"
#include "Food.h"
#include "TimeManager.h"
#include "InputManager.h"
class Frog : public GameObject
{
public:
	Frog();
	void Respawn();
	void AddMovement(Vector2 dir);
	bool isMoving();
	void Update() override;
	void Render() override;
	void AddFood(Food* food);
private:
	Vector2 targetPosition;
	bool moving, hasFood;
	Food* food;
};