#include "Log.h"

Log::Log(int length)
{
	this->length = length;

	SDL_Rect* source = new SDL_Rect();

	source->x = 96;
	source->y = 128;
	source->w = 48;
	source->h = 16;

	SDL_Rect* target = new SDL_Rect();

	target->x = 0;
	target->y = 0;
	target->w = 16 * length;
	target->h = 16;

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = target->w / 2,
		center.y = target->h / 2,
	};

	ImageRenderer* idle = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
	idle->Load("./resources/assets2.png");
	renderers.push_back(idle);
}

void Log::Update()
{
	transform.position.x += 50 * TM->GetDeltaTime();



	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();
}

void Log::Render()
{
	renderers[0]->Render();
}
