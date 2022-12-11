#include "EndTileItem.h"

EndTileItem::EndTileItem(float duration, bool isLethal, std::string spritePath)
{
	this->duration = duration;
	this->isLethal = isLethal;
	this->spritePath = spritePath;
	isFinished = false;
}

bool EndTileItem::IsFinished()
{
	return isFinished;
}