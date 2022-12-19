#include "Frog.h"

Frog::Frog()
{
	moving = false;
	hasFood = false;
	currentRow = 1;
	lastRow = currentRow;
	dead = false;
	animDeathTime = 0;

	SDL_Rect* source = new SDL_Rect();

	source->x = 0;
		source->y = 0;
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

	SDL_Rect* sourceDeath = new SDL_Rect();

	sourceDeath->x = 0;
	sourceDeath->y = 48;
	sourceDeath->w = 16;
	sourceDeath->h = 16;

	AnimatedImageRenderer* move = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center, 16, 16, 3, 0.4, 3, true);
	ImageRenderer* idle = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, source, center);
	AnimatedImageRenderer* die = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, sourceDeath, center, 16, 16, 5, 0.2, 5, false);


	idle->Load("./resources/assets2.png");
	move->Load("./resources/assets2.png");
	die->Load("./resources/assets2.png");
	renderers.push_back(idle);
	renderers.push_back(move);
	renderers.push_back(die);
}

void Frog::Respawn(Vector2 startPos)
{
	moving = false;
	hasFood = false;
	currentRow = 1;
	lastRow = currentRow;
	dead = false;
	animDeathTime = 0;

	SetPosition(startPos);
}

void Frog::AddMovement(Vector2 dir)
{
	moving = true;
	transform.position.x += dir.x * TM->GetDeltaTime();
	transform.position.y += dir.y * TM->GetDeltaTime();
	currentRow = transform.position.x / 16;
	if (currentRow > lastRow)
	{
		lastRow = currentRow;
		AddScore(10);
	}
	moving = false;
}

bool Frog::isMoving()
{
	return moving;
}

void Frog::AddScore(int score)
{
	PM->AddScore(score);
}

bool Frog::FinishedDeathAnimation()
{
	if (dead) {
		animDeathTime += TM->GetDeltaTime();
		if (animDeathTime > 1) {
			return true;
		}
	}
	return false;
}

void Frog::AddFood()
{
	if (!hasFood)
	{
		hasFood = true;
		AddScore(100);
	}
}

void Frog::Update()
{	
	if (!isMoving() && !dead)
	{
		Vector2 dir(0, 0);
		if (IM->CheckKeyState(SDLK_w, PRESSED))
		{
			dir.x = 0;
			dir.y = 16;
		}
		if (IM->CheckKeyState(SDLK_s, PRESSED))
		{
			dir.x = 0;
			dir.y = -16;
		}
		if (IM->CheckKeyState(SDLK_d, PRESSED))
		{
			dir.x = 16;
			dir.y = 0;
		}
		if (IM->CheckKeyState(SDLK_a, PRESSED))
		{
			dir.x = -16;
			dir.y = 0;
		}
		AddMovement(dir);
	}
	for (int i = 0; i < renderers.size(); i++) {
		renderers[i]->SetPosition(transform.position);
		renderers[i]->Update();
	}
}

void Frog::Render()
{
	/*if(!isMoving())
		renderers[0]->Render();
	else*/ if(!dead){
		renderers[1]->Render();
	}
	else {
		renderers[2]->Render();
	}
		
}
