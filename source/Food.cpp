#include "Food.h"

Food::Food(Log* log)
{
	this->log = log;
}

void Food::Update()
{
}

void Food::Render()
{
}

void Food::AttachToPlayer()
{
	if (!attachedToPlayer)
	{
		attachedToPlayer = true;
	}
}