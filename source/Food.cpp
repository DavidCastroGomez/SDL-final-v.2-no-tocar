#include "Food.h"

Food::Food(Log* log)
{
	this->log = log;
}

void Food::AttachToPlayer()
{
	if (!attachedToPlayer)
	{
		attachedToPlayer = true;
	}
}