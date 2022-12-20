#include "TextObject.h"

TextObject::TextObject(std::string text, Vector2 pos)
{
	int width = 6 * text.length();
	int heigth = 14;

	SDL_Rect* source = new SDL_Rect();

	source->x = 0;
	source->y = 0;
	source->w = 16;
	source->h = 16;

	SDL_Rect* target = new SDL_Rect();

	target->x = pos.x * 16;
	target->y = pos.y * 16;
	target->w = width;
	target->h = heigth;

	SDL_Point center{
		center.x = target->w / 2,
		center.y = target->h / 2,
	};

	SDL_Color white = { 255, 255, 255 };

	this->text = new TextRenderer(white, 255, pos, 0, Vector2(1, 1), target, source, text, center);
	this->text->Load("./resources/fonts/hyperspace.ttf");
}

void TextObject::Update()
{
	text->Update();
}

void TextObject::Render()
{
	text->Render();
}
