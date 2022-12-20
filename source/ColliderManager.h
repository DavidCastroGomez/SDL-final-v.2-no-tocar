#pragma once
#include <vector>
#include "GameObject.h"

#define CM ColliderManager::GetInstance()

class ColliderManager
{
public:
	std::vector<GameObject*> GetColliders();
	void AddCollider(GameObject* go);
	void RemoveCollider(GameObject* go);
	static ColliderManager* GetInstance();
private:
	static ColliderManager* instance;
	std::vector<GameObject*> colliderVector;
	ColliderManager() = default;
	void SortVector();
};
