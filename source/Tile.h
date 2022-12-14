#pragma once
#include <SDL.h>
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile(bool isLethal, int type);
	void Update() override;
	void Render() override;
private:
	bool isLethal;
	ImageRenderer* image;
	
};