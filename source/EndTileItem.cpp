#include "EndTileItem.h"

EndTileItem::EndTileItem(float duration, bool isLethal)
{
	this->duration = duration;
	this->isLethal = isLethal;
	isFinished = false;

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
}

void EndTileItem::Render()
{
}

bool EndTileItem::IsFinished()
{
	return isFinished;
}