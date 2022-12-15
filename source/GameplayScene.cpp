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
	InsertTiles(RowTypes::BORDER, 11, y);
	y++;
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("Layout")->first_node(); pNode; pNode = pNode->next_sibling()) {
		int i = 0;
		
		switch (ConvertStrToRowType(pNode->name()))
		{
		case RowTypes::ENDZONE:
			break;
		case RowTypes::LOGRIVER:
		{
			Spawner* spawner = new Spawner("log");
			spawner->SetStartPosition(Vector2(-2*16, y));
			spawner->SetMinLength(std::stof(pNode->first_attribute("minLength")->value()));
			spawner->SetMaxLength(std::stof(pNode->first_attribute("maxLength")->value()));
			for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				switch (i) {
				case 0:
					spawner->SetMinSpawnTime(std::stof(pNodeI->first_attribute("min")->value()));
					spawner->SetMaxSpawnTime(std::stof(pNodeI->first_attribute("max")->value()));
					break;
				case 1:
					spawner->SetVariantChance(std::stoi(pNodeI->value()));
					break;
				case 2:
					spawner->SetSnakeChance(std::stoi(pNodeI->value()));
					break;
				}
				i++;
			}
			spawners.push_back(spawner);
		}
			break;
		case RowTypes::TURTLESRIVER:
		{
			Spawner* spawner = new Spawner("turtle");
			spawner->SetStartPosition(Vector2(13*16, y*16));
			spawner->SetMinLength(std::stof(pNode->first_attribute("minLength")->value()));
			spawner->SetMaxLength(std::stof(pNode->first_attribute("maxLength")->value()));
			for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				switch (i) {;
				case 0:
					spawner->SetMinSpawnTime(std::stof(pNodeI->first_attribute("min")->value()));
					spawner->SetMaxSpawnTime(std::stof(pNodeI->first_attribute("max")->value()));
					break;
				case 1:
					spawner->SetVariantChance(std::stoi(pNodeI->value()));
					break;
				}
				i++;
			}
			spawners.push_back(spawner);
		}
				break;
		case RowTypes::ROAD:
		{
			Spawner* spawner = new Spawner("car");
			spawner->SetCarId(pNode->first_attribute("carID")->value());
			for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
				switch (i) {
				case 0:
					spawner->SetMinSpawnTime(std::stof(pNodeI->first_attribute("min")->value()));
					spawner->SetMaxSpawnTime(std::stof(pNodeI->first_attribute("max")->value()));
					break;
				case 1:
					spawner->SetStartVelocity(std::stoi(pNodeI->value()));
					break;
				}
				i++;
			}
			if (y % 2 == 0) {
				spawner->SetStartPosition(Vector2(13 * 16, y * 16));
			}
			else {
				spawner->SetStartPosition(Vector2(-2 * 16, y * 16));
			}
			
			spawners.push_back(spawner);
		}
			break;
		case RowTypes::SAFEZONE:
			break;
		}
		
		InsertTiles(ConvertStrToRowType(pNode->name()), 11, y);

		y++;
	}
	InsertTiles(RowTypes::BORDER, 11, y);
}

GameplayScene::RowTypes GameplayScene::ConvertStrToRowType(std::string str)
{
	RowTypes type = RowTypes::NONE;
	if (str == "EndZone")
		type = RowTypes::ENDZONE;
	else if (str == "LogRiver")
		type = RowTypes::LOGRIVER;
	else if (str == "TurtlesRiver")
		type = RowTypes::TURTLESRIVER;
	else if (str == "SafeZone")
		type = RowTypes::SAFEZONE;
	else if (str == "Road")
		type = RowTypes::ROAD;
	return type;
}

void GameplayScene::InsertTiles(RowTypes type, int numOfTiles = 13, int row = 0)
{
	for (int i = 0; i < numOfTiles; i++) {
		int tileType;
		if (type == RowTypes::LOGRIVER || type == RowTypes::TURTLESRIVER) {
			tileType = 2;
		}
		else if (type == RowTypes::ENDZONE) {
			tileType = i % 2;
			if (tileType == 1) {

			}
		}
		else if (type == RowTypes::SAFEZONE) {
			tileType = 3;
		}
		else if (type == RowTypes::ROAD) {
			tileType = 4;
		}
		else if (type == RowTypes::BORDER) {
			tileType = 5;
		}
		else {
			assert(-1);
		}
		Tile* newTile = new Tile(false, tileType);
		newTile->SetPosition(Vector2(i * 16, row * 16));
		tiles.push_back(newTile);

	}
}

void GameplayScene::Update()
{
	for (int i = 0; i < spawners.size(); i++)
	{
		GameObject* spawned = spawners[i]->Update();
		if (spawned != nullptr) {
			objects.push_back(spawned);
		}
	}

	for (int i = 0; i < tiles.size(); i++) {
		tiles[i]->Update();
	}

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Update();
	}
}

void GameplayScene::Render()
{
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i]->Render();
	}

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Render();
	}

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Render();
	}
}

void GameplayScene::OnEnter()
{
	/*
	* player = new Frog();
	* Frog.transform.SetPosition(RM->windowWidth / 2, 0);
	*/
	LoadLevelFromFile("./resources/level.xml");
}

void GameplayScene::OnExit()
{
}
