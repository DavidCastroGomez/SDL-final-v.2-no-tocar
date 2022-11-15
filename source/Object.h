#pragma once
#include "Transform.h"
#include "AABB.h"
#include "Vector2.h"

class Object
{
public:
	Transform transform;
	AABB boundingBox;
	Vector2 velocity;

	Object() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
	Transform GetTransform();
	AABB GetBoundingBox();
	Vector2 GetVelocity();
	void SetPosition(Vector2);
	void SetRotation(Vector2);
	void SetScale(Vector2);
	void SetTransform(Transform);
	void SetVelocity(Vector2);
};

