#include "Snake.h"

Snake::Snake(Log* log)
{
	this->log = log;
	this->speed = 80;

	SDL_Rect* source = new SDL_Rect();

	source->x = 0;
	source->y = 128;
	source->w = 32;
	source->h = 16;

	SDL_Rect* target = new SDL_Rect();

	target->x = 0;
	target->y = 0;
	target->w = 32;
	target->h = 16;

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = target->w / 2,
		center.y = target->h / 2,
	};

	AnimatedImageRenderer* move = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center, 16, 16, 3, 0.5, 3, true);
	move->Load("./resources/assets2.png");
	renderers.push_back(move);

	Vector2 aux(source->w, source->h);
	GetBoundingBox().SetSize(aux);
	aux.x = 0;
	aux.y = 0;
	GetBoundingBox().SetTopLeft(aux);
	CM->AddCollider(this);
}

void Snake::Update()
{
	SetPosition(log->transform.position);

	transform.position.x += speed * TM->GetDeltaTime();
	if (transform.position.x > log->GetTransform().position.x + log->GetBoundingBox().GetSize().x || transform.position.x < log->GetTransform().position.x) {
		speed = -speed;
	}

	GetBoundingBox().SetTopLeft(transform.position);
	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();

}

void Snake::Render()
{
	renderers[0]->Render();
}
