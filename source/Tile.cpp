#include "Tile.h"

Tile::Tile(bool isLethal, int type)
{
	this->isLethal = isLethal;

	SDL_Rect* source = new SDL_Rect();

	source->w = 16;
	source->h = 16;

	switch (type)
	{
	case 0:	//EndLine
		source->x = 9;
		source->y = 1;
		source->w = 24;
		source->h = 24;
		break;
	case 1:	//Water End
		source->x = 33;
		source->y = 1;
		source->w = 24;
		source->h = 24;
		break;
	case 2:	//Water
		source->x = 9;
		source->y = 25;
		Vector2 aux(source->x, source->y);
		GetBoundingBox().SetSize(aux);
		aux.x = 0;
		aux.y = 0;
		GetBoundingBox().SetTopLeft(aux);
		CM->AddCollider(this);
		break;
	case 3:	//SafeZone
		source->x = 9;
		source->y = 105;
		break;
	case 4:	//Road
		source->x = 9;
		source->y = 125;
		break;
	case 5: //BORDER
		source->x = 9;
		source->y = 125;
	default:
		assert(-1);
		break;
	}


	SDL_Rect* target = new SDL_Rect();

	target->x = 0;
	target->y = 0;
	target->w = 16;
	target->h = 16;

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = 0,
		center.y = 0,
	};

	ImageRenderer* image = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
	image->Load("./resources/assets.png");
	renderers.push_back(image);
}

void Tile::Update()
{
	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();
}

void Tile::Render()
{
	renderers[0]->Render();
}