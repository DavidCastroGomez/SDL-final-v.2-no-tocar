#include "Tile.h"

Tile::Tile(bool isLethal)
{
	this->isLethal = isLethal;
}

void Tile::Update()
{

}

void Tile::Render()
{
	Renderer::Render();
}