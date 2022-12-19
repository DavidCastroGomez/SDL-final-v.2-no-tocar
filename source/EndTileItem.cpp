#include "EndTileItem.h"

EndTileItem::EndTileItem(float duration, bool isLethal, Spawner* spawner)
{
	this->duration = duration;
	this->isLethal = isLethal;
	isFinished = false;
	this->spawner = spawner;

	this->currentDuration = 0;

	SDL_Rect* source = new SDL_Rect();

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

	if (isLethal) {
		source->x = 80;
		source->y = 96;
		AnimatedImageRenderer* move = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center, 16, 16, 2, 0.4, 2, false);
		move->Load("./resources/assets2.png");
		renderers.push_back(move);
	}
	else {

		source->x = 32;
		source->y = 96;
		ImageRenderer* idle = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
		idle->Load("./resources/assets2.png");
		renderers.push_back(idle);
	}	
	
}

void EndTileItem::Update()
{
	currentDuration += TM->GetDeltaTime();
	if (currentDuration > duration) {
		isFinished = true;
		spawner->SetCanSpawn(true);
	}
	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();
}

void EndTileItem::Render()
{
	renderers[0]->Render();
}

bool EndTileItem::IsFinished()
{
	return isFinished;
}