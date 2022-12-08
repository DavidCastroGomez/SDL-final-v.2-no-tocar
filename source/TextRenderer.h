#pragma once
#include "Renderer.h"
#include "SDL_ttf.h"

class TextRenderer :
    public Renderer
{
private:
    std::string text;

public:
    TextRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect targetRect, SDL_Rect sourceRect, std::string text);

    void Load(std::string) override;

    void Update(float) override;
    void Render() override;

    std::string GetText();
    void SetText(std::string);
};

