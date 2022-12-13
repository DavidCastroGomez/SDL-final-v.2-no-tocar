#include "GameplayScene.h"

void GameplayScene::LoadLevelFromFile(std::string path)
{
	rapidxml::xml_document<> xmlLevel;
	std::ifstream levelFile(path);
	assert(levelFile.is_open());

	std::stringstream buffer;
	buffer << levelFile.rdbuf();
	levelFile.close();
	std::string content = buffer.str();
	xmlLevel.parse<0>(&content[0]);

	rapidxml::xml_node<>* pRoot = xmlLevel.first_node();

	//timemanager.time = std::stoi(pRoot->first_node("MaxTime")->value());

	int y = 0;
	for (rapidxml::xml_node<>* pNode = pRoot->first_node(); pNode; pNode = pNode->next_sibling()) {
		int i = 0;
		switch (ConvertStrToRowType(pNode->name()))
		{
		case RowTypes::ENDZONE:
			break;
		case RowTypes::LOGRIVER:
			Spawner spawner;
			for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				switch (i) {
				case 0:
					//spawner.object.minLength = pNodeI->first_attribute("minLength");
					//spawner.object.maxLength = pNodeI->first_attribute("maxLength");
				case 1:
					//spawner.minSpawnRate = pNodeI->first_attribute("min");
					//spawner.maxSpawnRate = pNodeI->first_attribute("max");
					break;
				case 2:
					//spawner.crocodileChance = pNodeI->value();
					break;
				case 3:
					//spawner.snakeChance = pNodeI->value();
					break;
				}
				i++;
			}
			//spawner.push_back(spawner());
			break;
		case RowTypes::TURTLESRIVER:
			Spawner spawner;
			for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				switch (i) {
				case 0:
					//spawner.object.minLength = pNodeI->first_attribute("minLength");
					//spawner.object.maxLength = pNodeI->first_attribute("maxLength");
				case 1:
					//spawner.minSpawnRate = pNodeI->first_attribute("min");
					//spawner.maxSpawnRate = pNodeI->first_attribute("max");
					break;
				case 2:
					//spawner.crocodileChance = pNodeI->value();
					break;
				}
				i++;
			}
				break;
		case RowTypes::ROAD:
			Spawner spawner;
			for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				switch (i) {
				case 0:
					//spawner.object = pNodeI->first_attribute("carID");
				case 1:
					//spawner.minSpawnRate = pNodeI->first_attribute("min");
					//spawner.maxSpawnRate = pNodeI->first_attribute("max");
					break;
				case 2:
					//spawner.speed = pNodeI->value();
					break;
				}
				i++;
			}
			break;
		case RowTypes::SAFEZONE:
			break;						
		}
		InsertTiles(ConvertStrToRowType(pNode->name()), 13, y);

		y++;
	}
}

GameplayScene::RowTypes GameplayScene::ConvertStrToRowType(std::string str)
{
    RowTypes type = RowTypes::NONE;
    if (str == "ENDZONE")
        type = RowTypes::ENDZONE;
    else if (str == "LOGRIVER")
        type = RowTypes::LOGRIVER;
    else if (str == "TURTLESRIVER")
        type = RowTypes::TURTLESRIVER;
    else if (str == "SAFEZONE")
        type = RowTypes::SAFEZONE;
    return type;
}

void GameplayScene::InsertTiles(RowTypes type, int numOfTiles = 13, int row)
{
	for (int i = 0; i < numOfTiles; i++) {
		//Tile newTile = Tile();
		// newTile.SetPosition(i, row);
		//tiles.push_back(newTile);
	}
}

void GameplayScene::Update()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i].Update();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i].Update();
	}
}

void GameplayScene::Render()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i].Render();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i].Render();
	}
}

void GameplayScene::OnEnter()
{
	/*
	* player = new Frog();
	* Frog.transform.SetPosition(RM->windowWidth / 2, 0);
	*/
	LoadLevelFromFile("../resources/level.xml");	
}

void GameplayScene::OnExit()
{
}
