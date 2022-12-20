#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Vector2.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include "LifeManager.h"
#include "AABB.h"

class Frog : public GameObject
{
public:
	Frog();
	void Respawn();
	void AddMovement(Vector2 dir);
	bool isMoving();
	void Update() override;
	void Render() override;
	void AddFood();
	void AddScore(int score);
private:
	Vector2 targetPosition;
	Vector2 initialPosition;
	bool moving, hasFood;
	int lastRow, currentRow;
};