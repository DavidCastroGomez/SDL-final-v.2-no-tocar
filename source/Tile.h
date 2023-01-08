#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "ColliderManager.h"
class Tile : public GameObject
{
public:
	Tile(bool isLethal, int type);
	void Update() override;
	void Render() override;
	bool GetLethal();
private:
	bool isLethal;
	
};