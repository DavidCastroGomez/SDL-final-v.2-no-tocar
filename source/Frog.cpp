#include "Frog.h"

Frog::Frog()
{
	moving = false;
	hasFood = false;
	currentRow = 1;
	lastRow = currentRow;
	Vector2 aux(16, 16);
	GetBoundingBox().SetSize(aux);
	aux.x = 0;
	aux.y = 0;
	GetBoundingBox().SetTopLeft(aux);
	dead = false;
	animDeathTime = 0;
	initialPosition = aux;

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
	AM->PlaySFX("jump", 0);
	moving = true;
	switch ((int)dir.x)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		for (int i = 0; i < 64; i++)
			transform.position.x += 32 * TM->GetDeltaTime();
		break;
	}
	case -1:
	{
		for (int i = 0; i > -64; i--)
			transform.position.x -= 32 * TM->GetDeltaTime();
		break;
	}
	default:
	{
		break;
	}
	}
	switch ((int)dir.y)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		for (int i = 0; i < 64; i++)
			transform.position.y += 32 * TM->GetDeltaTime();
		break;
	}
	case -1:
	{
		for (int i = 0; i > -64; i--)
			transform.position.y -= 32 * TM->GetDeltaTime();
		break;
	}
	default:
	{
		break;
	}
	}
	currentRow = transform.position.x / 16;
	if (currentRow > lastRow)
	{
		lastRow = currentRow;
		AddScore(10);
	}
	moving = false;

	for (int i = 0; i < CM->GetColliders().size(); i++)
	{
		auto temp = CM->GetColliders()[i]->GetBoundingBox();
		if (GetBoundingBox().CheckOverlappingAABB(&temp))
			Respawn(initialPosition);
	}
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
	if (!isMoving() && moveDelay >= 10)
	{
		if (IM->CheckKeyState(SDLK_w, PRESSED))
		{
			targetPosition.x = 0;
			targetPosition.y = -1;
			AddMovement(targetPosition);
			moveDelay = 0;
		}
		else if (IM->CheckKeyState(SDLK_s, PRESSED))
		{
			targetPosition.x = 0;
			targetPosition.y = 1;
			AddMovement(targetPosition);
			moveDelay = 0;
		}
		else if (IM->CheckKeyState(SDLK_a, PRESSED))
		{
			targetPosition.x = -1;
			targetPosition.y = 0;
			AddMovement(targetPosition);
			moveDelay = 0;
		}
		else if (IM->CheckKeyState(SDLK_d, PRESSED))
		{
			targetPosition.x = 1;
			targetPosition.y = 0;
			AddMovement(targetPosition);
			moveDelay = 0;
		}
		
	}
	moveDelay++;
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
