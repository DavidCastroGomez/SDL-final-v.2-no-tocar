#pragma once
#include "Object.h"
#include "TextRenderer.h"
#include "RendererManager.h"
#include "Vector2.h"
#include <string>
class TextObject : public Object
{
public:
	TextObject(std::string text, Vector2 pos);

	void Update() override;
	void Render() override;

	TextRenderer* text;
};

