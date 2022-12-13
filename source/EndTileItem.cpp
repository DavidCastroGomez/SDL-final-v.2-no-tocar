#include "EndTileItem.h"

EndTileItem::EndTileItem(float duration, bool isLethal, std::string spritePath)
{
	this->duration = duration;
	this->isLethal = isLethal;
	this->spritePath = spritePath;
	isFinished = false;
}

void EndTileItem::Update()
{
}

void EndTileItem::Render()
{
}

bool EndTileItem::IsFinished()
{
	return isFinished;
}