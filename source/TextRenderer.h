#pragma once
#include "Renderer.h"
#include "SDL_ttf.h"

class TextRenderer :
    public Renderer
{
private:
    std::string text;
    TTF_Font* font;

public:
    TextRenderer(SDL_Color color, float alpha, Vector2 position, float rotation, Vector2 scale, SDL_Rect* targetRect, SDL_Rect* sourceRect, std::string text, SDL_Point center);

    void Load(std::string) override;

    void Update() override;
    void Render() override;

    std::string GetText();
    void SetText(std::string);
};

