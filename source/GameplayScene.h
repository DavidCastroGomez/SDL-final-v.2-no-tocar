#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Tile.h"
#include "Spawner.h"
#include "../dependencies/XML/rapidxml.hpp"
#include "../dependencies/XML/rapidxml_utils.hpp"
#include "../dependencies/XML/rapidxml_iterators.hpp"
#include "../dependencies/XML/rapidxml_print.hpp"
#include <fstream>
#include <sstream>
class GameplayScene : public Scene
{
private:
    std::vector<Spawner> spawner;
    std::vector<GameObject> tiles;
    bool endPosition[5];
    //Frog player;
    static int level;
    int score;

    void LoadLevelFromFile(std::string path);

    enum RowTypes { ENDZONE, LOGRIVER, TURTLESRIVER, SAFEZONE, ROAD , NONE};

    RowTypes ConvertStrToRowType(std::string path);
    void InsertTiles(RowTypes type, int numOfTiles, int y);

public:

    GameplayScene() = default;
    void Update() override;

    void Render() override;

    void OnEnter() override;

    void OnExit() override;
    

};

