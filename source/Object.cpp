#include "Object.h"

Transform Object::GetTransform()
{
	return transform;
}

AABB Object::GetBoundingBox()
{
	return boundingBox;
}

Vector2 Object::GetVelocity()
{
	return velocity;
}

void Object::SetPosition(Vector2 p)
{
	this->transform.position = p;
}

void Object::SetRotation(Vector2 r)
{
	this->transform.rotation = r;
}

void Object::SetScale(Vector2 s)
{
	this->transform.scale = s;
}

void Object::SetTransform(Transform t)
{
	this->transform = t;
}

void Object::SetVelocity(Vector2 v)
{
	this->velocity = v;
}
