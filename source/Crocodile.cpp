#include "Crocodile.h"

Crocodile::Crocodile(float openMouthDuration, float closedMouthDuration)
{
	this->openMouthDuration = openMouthDuration;
	this->closedMouthDuration = closedMouthDuration;
	this->elapsedTime = 0.f;
	isMouthOpen = false;

	SDL_Rect* sourceBody = new SDL_Rect();

	sourceBody->x = 0;
	sourceBody->y = 112;
	sourceBody->w = 32;
	sourceBody->h = 16;

	SDL_Rect* targetBody = new SDL_Rect();

	targetBody->x = 0;
	targetBody->y = 0;
	targetBody->w = 32;
	targetBody->h = 16;

	SDL_Color color = { 255, 255, 255 };

	SDL_Point center{
		center.x = targetBody->w / 2,
		center.y = targetBody->h / 2,
	};

	ImageRenderer* body = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), targetBody, sourceBody, center);
	body->Load("./resources/assets2.png");
	renderers.push_back(body);

	SDL_Rect* sourceHead1 = new SDL_Rect();

	sourceHead1->x = 32;
	sourceHead1->y = 112;
	sourceHead1->w = 16;
	sourceHead1->h = 16;

	SDL_Rect* targetHead = new SDL_Rect();

	targetHead->x = 0;
	targetHead->y = 0;
	targetHead->w = 16;
	targetHead->h = 16;

	SDL_Point center2{
		center.x = targetHead->w / 2,
		center.y = targetHead->h / 2,
	};

	ImageRenderer* head1 = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), targetHead, sourceHead1, center2);
	head1->Load("./resources/assets2.png");
	renderers.push_back(head1);

	SDL_Rect* sourceHead2 = new SDL_Rect();

	sourceHead2->x = 48;
	sourceHead2->y = 112;
	sourceHead2->w = 16;
	sourceHead2->h = 16;

	ImageRenderer* head2 = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), targetHead, sourceHead2, center2);
	head2->Load("./resources/assets2.png");
	renderers.push_back(head2);
}

void Crocodile::Update()
{
	elapsedTime += TM->GetDeltaTime();

	if (elapsedTime > openMouthDuration && IsMouthOpen())
	{
		elapsedTime = 0.f;
		isMouthOpen = false;
	}
	else if (elapsedTime > closedMouthDuration && !IsMouthOpen())
	{
		elapsedTime = 0.f;
		isMouthOpen = true;
	}
	transform.position.x += 40 * TM->GetDeltaTime();

	renderers[0]->SetPosition(transform.position);
	renderers[0]->Update();

	if (isMouthOpen) {
		renderers[1]->SetPosition(Vector2(transform.position.x + 32, transform.position.y));
		renderers[1]->Update();
	}
	else {
		renderers[2]->SetPosition(Vector2(transform.position.x + 32, transform.position.y));
		renderers[2]->Update();
	}

}

void Crocodile::Render()
{
	renderers[0]->Render();
	if (isMouthOpen) {
		renderers[1]->Render();
	}
	else {
		renderers[2]->Render();
	}
}

bool Crocodile::IsMouthOpen()
{
	return isMouthOpen;
}