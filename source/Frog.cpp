#include "Frog.h"

Frog::Frog()
{
	canMove = true;
	moving = false;
	hasFood = false;
	moveTime = 0.125;
	moveDelay = 0.1;
	currentMoveTime = 0;
	currentRow = 0;
	rotation = 0;
	lastRow = currentRow;
	checkForMovePoint = true;
	Vector2 aux(16, 16);
	GetBoundingBox().SetSize(aux);
	aux.x = 0;
	aux.y = 0;
	GetBoundingBox().SetTopLeft(aux);
	dead = false;
	animDeathTime = 0;

	initialPosition.x = RM->windowWidth / 2 - 8;
	initialPosition.y = RM->windowHeight - 32;

	SDL_Rect* sourceIdle = new SDL_Rect();

	sourceIdle->x = 0;
	sourceIdle->y = 0;
	sourceIdle->w = 16;
	sourceIdle->h = 16;

	SDL_Rect* sourceMove = new SDL_Rect();

	sourceMove->x = 0;
	sourceMove->y = 0;
	sourceMove->w = 16;
	sourceMove->h = 16;

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

	ImageRenderer* idle = new ImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, sourceIdle, center);
	AnimatedImageRenderer* move = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, sourceMove, center, 16, 16, 3, 0.2, 3, true);
	AnimatedImageRenderer* die = new AnimatedImageRenderer(color, 255, Vector2(0, 0), 0, Vector2(1, 1), target, sourceDeath, center, 16, 16, 5, 0.2, 5, true);


	idle->Load("./resources/assets2.png");
	move->Load("./resources/assets2.png");
	die->Load("./resources/assets2.png");
	renderers.push_back(idle);
	renderers.push_back(move);
	renderers.push_back(die);
}

void Frog::Respawn(Vector2 startPos)
{
	AM->PlaySFX("death", 0);
	canMove = true;
	moving = false;
	hasFood = false;
	currentRow = 1;
	dead = false;
	animDeathTime = 0;
	rotation = 0;

	SetPosition(startPos);
}

void Frog::AddMovement(Vector2 dir)
{
	currentMoveTime += TM->GetDeltaTime();

	switch ((int)dir.x)
	{
	case 0:
		break;
	case 1:
		transform.position.x += 128 * TM->GetDeltaTime();
		rotation = 90;
		break;
	case -1:
		transform.position.x -= 128 * TM->GetDeltaTime();
		rotation = 270;
		break;
	default:
		break;
	}
	switch ((int)dir.y)
	{
	case 0:
		break;
	case 1:
		transform.position.y += 128 * TM->GetDeltaTime();
		rotation = 180;
		if (checkForMovePoint) {
			currentRow--;
			checkForMovePoint = false;
		}
		break;
	case -1:
		transform.position.y -= 128 * TM->GetDeltaTime();
		rotation = 0;
		if (checkForMovePoint) {
			currentRow++;
			checkForMovePoint = false;
		}
		break;
	default:
		break;
	}

	if (currentRow > lastRow)
	{
		lastRow = currentRow;
		AddScore(10);
	}

	for (int i = 0; i < CM->GetColliders().size(); i++)
	{
		auto temp = CM->GetColliders()[i]->GetBoundingBox();
		if (GetBoundingBox().CheckOverlappingAABB(&temp))
			dead = true;
	}

	if (currentMoveTime > moveTime) {
		targetDirection = Vector2(0, 0);
		if (currentMoveTime > moveTime + moveDelay) {
			moving = false;
			currentMoveTime = 0;
			canMove = true;
			checkForMovePoint = true;
		}
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
		AM->LoadSFX("no lives");
		animDeathTime += TM->GetDeltaTime();
		if (animDeathTime > 2) {
			return true;
		}
	}
	return false;
}

void Frog::SetDead(bool b)
{
	dead = b;
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
	if (canMove && !dead)
	{
		if (IM->CheckKeyState(SDLK_w, PRESSED))
		{
			targetDirection.x = 0;
			targetDirection.y = -1;
			moving = true;
			canMove = false;
			AM->PlaySFX("jump", 0);
		}
		else if (IM->CheckKeyState(SDLK_s, PRESSED))
		{
			targetDirection.x = 0;
			targetDirection.y = 1;
			moving = true;
			canMove = false;
			AM->PlaySFX("jump", 0);
		}
		else if (IM->CheckKeyState(SDLK_a, PRESSED))
		{
			targetDirection.x = -1;
			targetDirection.y = 0;
			moving = true;
			canMove = false;
			AM->PlaySFX("jump", 0);
		}
		else if (IM->CheckKeyState(SDLK_d, PRESSED))
		{
			targetDirection.x = 1;
			targetDirection.y = 0;
			moving = true;
			canMove = false;
			AM->PlaySFX("jump", 0);
		}
	}
	if (moving) {
		AddMovement(targetDirection);
	}

	for (int i = 0; i < renderers.size(); i++) {
		renderers[i]->SetPosition(transform.position);
		renderers[i]->SetRotation(rotation);
		renderers[i]->Update();
	}
}

void Frog::Render()
{
	if (!moving)
		renderers[0]->Render();
	else {
		renderers[1]->Render();
	}

	if (dead) {
		renderers[2]->Render();
	}

}

Vector2 Frog::GetInitialPosition()
{
	return initialPosition;
}