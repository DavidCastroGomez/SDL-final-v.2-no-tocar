#include "Food.h"

Food::Food(Log* log)
{
	this->log = log;

	SDL_Rect* source = new SDL_Rect();

	source->x = 0;
	source->y = 16;
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

	ImageRenderer* idle = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
	AnimatedImageRenderer* move = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center, 16, 16, 3, 0.5, 3, false);
	move->Load("./resources/assets2.png");
	idle->Load("./resources/assets2.png");
	renderers.push_back(move);
	renderers.push_back(idle);
}

void Food::Update()
{
	if (!attachedToPlayer) {
		SetPosition(log->transform.position);

		if (isMoving) {
			//move
			renderers[0]->SetPosition(transform.position);
			renderers[0]->Update();
		}
		else {
			renderers[1]->SetPosition(transform.position);
			renderers[1]->Update();
		}	
	}
	else {
		SetPosition(frog->transform.position);
		renderers[1]->SetPosition(transform.position);
		renderers[1]->Update();
	}
	
}

void Food::Render()
{
	if (attachedToPlayer || !isMoving) {
		renderers[1]->Render();
	}
	else {
		renderers[0]->Render();
	}
}

void Food::AttachToPlayer(Frog* frog)
{
	if (!attachedToPlayer)
	{
		attachedToPlayer = true;
		this->frog = frog;
	}
}