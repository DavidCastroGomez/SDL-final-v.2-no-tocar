#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Vector2.h"
#include "Food.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ScoreManager.h"
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
	void AddScore(int score);
private:
	Vector2 targetPosition;
	Vector2 initialPosition;
	bool moving, hasFood;
	Food* food;
	int lastRow, currentRow;
};