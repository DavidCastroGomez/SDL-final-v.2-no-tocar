#pragma once
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include "GameObject.h"
#include "Vector2.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include "LifeManager.h"
#include "ColliderManager.h"
#include "AudioManager.h"

class Frog : public GameObject
{
public:
	Frog();
	void Respawn(Vector2 startPos);
	void AddMovement(Vector2 dir);
	bool isMoving();
	void Update() override;
	void Render() override;
	void AddFood();
	void AddScore(int score);
	bool FinishedDeathAnimation();
private:
	Vector2 targetDirection;
	Vector2 initialPosition;
	bool canMove, moving, hasFood;
	int lastRow, currentRow;
	bool dead;
	float animDeathTime;
	float moveTime, currentMoveTime, moveDelay;
	float rotation;
	bool checkForMovePoint;
};