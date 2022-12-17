#pragma once
#include <string>
#include <SDL_image.h>
#include "GameObject.h"
class Car : public GameObject
{
public:
	Car(std::string carId, int speed);
	void Update() override;
	void Render() override;
private:
	std::string carId;
	int speed;
};