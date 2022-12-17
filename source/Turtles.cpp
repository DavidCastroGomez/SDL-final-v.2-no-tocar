#include "Turtles.h"

Turtles::Turtles()
{
	SDL_Rect* source = new SDL_Rect();

	source->x = 0;
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

void Turtles::Update()
{
	transform.position.x += -40 * TM->GetDeltaTime();
	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();
}

void Turtles::Render()
{
	renderers[0]->Render();
}
