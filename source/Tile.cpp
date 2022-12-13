#include "Tile.h"

Tile::Tile(bool isLethal, int type)
{
	this->isLethal = isLethal;

	SDL_Rect source{
	source.x = 0,
	source.y = 0,
	source.w = 16,
	source.h = 16
	};

	switch (type)
	{
	case 0:	//EndLine
		source.x = 10;
		source.y = 10;
		source.w = 24;
		source.h = 24;
		break;
	case 1:	//Water
		source.x = 9;
		source.y = 25;
		break;
	case 2:	//SafeZone
		source.x = 9;
		source.y = 105;
		break;
	case 3:	//Road
		source.x = 9;
		source.y = 125;
		break;
	default:
		assert(-1);
		break;
	}


	SDL_Rect target{
		target.x = 0,
		target.y = 0,
		target.w = 16,
		target.h = 16
	};

	SDL_Color color = { 255, 255, 255};

	SDL_Point center{
		center.x = 0,
		center.y = 0,
	};

	image = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1,1), target, source, center);
	image->Load("./resources/assets.png");
}

void Tile::Update()
{
	image->SetPosition(transform.position);
	image->Update();
}

void Tile::Render()
{
	image->Render();
}