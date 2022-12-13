#pragma once
#include <SDL.h>
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile(bool isLethal);
	void Update() override;
	void Render() override;
private:
	bool isLethal;
};