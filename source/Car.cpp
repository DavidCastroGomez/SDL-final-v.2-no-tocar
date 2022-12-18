#include "Car.h"

Car::Car(std::string carId, int speed)
{
	this->carId = carId;
	this->speed = speed * 20;

	SDL_Rect* source = new SDL_Rect();

	source->y = 0;
	source->w = 16;
	source->h = 16;

	if (carId == "racing0") {

		source->x = 48;
		this->speed = -this->speed;
		
	}
	else if (carId == "farming0") {
		source->x = 64;
	}
	else if (carId == "truck0") {
		source->x = 80;
		source->w = 32;
		this->speed = -this->speed;
	}
	else if (carId == "family0") {
		source->x = 112;
		this->speed = -this->speed;
	}
	else if (carId == "racing1") {
		source->x = 128;
	}

	SDL_Rect* target = new SDL_Rect();

	target->x = 0;
	target->y = 0;
	target->h = 16;

	if (carId == "truck0") {
		target->w = 32;
	}
	else {
		target->w = 16;
	}

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = target->w / 2,
		center.y = target->h / 2,
	};

	ImageRenderer* idle = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
	idle->Load("./resources/assets2.png");
	renderers.push_back(idle);
}

void Car::Update()
{
	transform.position.x += speed * TM->GetDeltaTime();

	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();
}

void Car::Render()
{
	renderers[0]->Render();
}
