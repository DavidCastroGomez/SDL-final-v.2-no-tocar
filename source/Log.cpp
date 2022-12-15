#include "Log.h"

Log::Log(int length)
{
	this->length = length;
}

void Log::Update()
{
	transform.position.x += 8 * TM->GetDeltaTime();
}

void Log::Render()
{
}
