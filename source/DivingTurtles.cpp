#include "DivingTurtles.h"

DivingTurtles::DivingTurtles(float diveDuration, float surfaceDuration) : Turtles()
{
	this->diveDuration = diveDuration;
	this->surfaceDuration = surfaceDuration;

	this->isDiving = false;

	this->elapsedTime = 0.f;
	
	SDL_Rect* source = new SDL_Rect();

	source->x = 48;
	source->y = 80;
	source->w = 16;
	source->h = 16;

	SDL_Rect* target = new SDL_Rect();

	target->x = 0;
	target->y = 0;
	target->w = 16;
	target->h = 16;

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = target->w / 2,
		center.y = target->h / 2,
	};

	AnimatedImageRenderer* move = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center, 16, 16, 3, 0.5, 3, true);
	move->Load("./resources/assets2.png");
	renderers.push_back(move);

}

void DivingTurtles::Render()
{
	if (isDiving) {
		renderers[1]->Render();
	}
	else {
		renderers[0]->Render();
	}
}

void DivingTurtles::Update()
{
	elapsedTime += TM->GetDeltaTime();

	if (elapsedTime > diveDuration && isDiving)
	{
		elapsedTime = 0.f;
		isDiving = false;
	}
	else if (elapsedTime > surfaceDuration && !isDiving)
	{
		elapsedTime = 0.f;
		isDiving = true;
	}
	transform.position.x -= 40 * TM->GetDeltaTime();

	if (isDiving) {
		renderers[1]->SetPosition(transform.position);
		renderers[1]->Update();
	}
	else {
		renderers[0]->SetPosition(transform.position);
		renderers[0]->Update();
	}
}
