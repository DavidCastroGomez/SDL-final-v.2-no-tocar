#include "ColliderManager.h"

ColliderManager* ColliderManager::instance = nullptr;

ColliderManager* ColliderManager::GetInstance()
{
	if (instance == nullptr)
		instance = new ColliderManager;
	return instance;
}

std::vector<GameObject*> ColliderManager::GetColliders()
{
	return colliderVector;
}

void ColliderManager::AddCollider(GameObject* go)
{
	colliderVector.push_back(go);
}

void ColliderManager::RemoveCollider(GameObject* go)
{
	for (int i = 0; i < colliderVector.size(); i++)
	{
		if (colliderVector[i] == nullptr)
		{
			colliderVector.push_back(colliderVector[i]);
		}
	}
	SortVector();
}

void ColliderManager::SortVector()
{
	GameObject* temp;
	for (int i = 0; i < colliderVector.size()-1; i++)
	{
		temp = colliderVector[i + 1];
		if (colliderVector[i] == nullptr)
		{
			colliderVector[i + 1] = colliderVector[i];
			colliderVector[i] = temp;
		}
	}
}