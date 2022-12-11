#pragma once
#include "Scene.h"
#include "GameObject.h"
class GameplayScene : public Scene
{
private:
    //Spawners spawner;
    std::vector<GameObject> tiles;
    bool endPosition[5];
    //Frog player;
    static int level;
    int score;

public:

    GameplayScene() = default;
    void Update() override;

    void Render() override;

    void OnEnter() override;

    void OnExit() override;
    

};

