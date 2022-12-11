#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Vector2.h"
#include "Food.h"
class Frog : public GameObject
{
public:
	Frog();
	void Respawn();
	void AddMovement(Vector2 dir);
	bool isMoving();
	void Update(float dt) override;
	void Render(SDL_Renderer*) override;
	void AddFood(Food* food);
private:
	Vector2 targetPosition;
	bool moving, hasFood;
	Food* food;
};