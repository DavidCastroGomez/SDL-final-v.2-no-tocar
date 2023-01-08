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

	Spawner* lastLogRow = nullptr;
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("Layout")->first_node(); pNode; pNode = pNode->next_sibling()) {
		int i = 0;
		
		switch (ConvertStrToRowType(pNode->name()))
		{
		case RowTypes::ENDZONE:
		{
			Spawner* spawner = new Spawner("end");
			spawner->SetVariantChance(std::stoi(pNode->first_attribute("hazardChance")->value()));

			for (int i = 0; i < 5; i++) {
				spawner->SetEndPositions(endPosition[i], i);
			}

			spawners.push_back(spawner);
			break;
		}
		case RowTypes::LOGRIVER:
		{
			Spawner* spawner = new Spawner("log");
			lastLogRow = spawner;
			spawner->SetStartPosition(Vector2(-3*16, y*16));
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

			std::string carId = pNode->first_attribute("carID")->value();

			spawner->SetCarId(carId);

			if (carId == "racing0" || carId == "truck0" || carId == "family0") {
				spawner->SetStartPosition(Vector2(13 * 16, y * 16));
			}
			else {
				spawner->SetStartPosition(Vector2(-2 * 16, y * 16));
			}

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
			
			spawners.push_back(spawner);
		}
			break;
		case RowTypes::SAFEZONE:
			break;
		}
		
		InsertTiles(ConvertStrToRowType(pNode->name()), 11, y);

		y++;
	}
	if (lastLogRow != nullptr) {
		lastLogRow->SetLastRow(true);
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
	bool endZoneFirstSpawner = true;
	for (int i = 0; i < numOfTiles; i++) {
		int tileType;
		if (type == RowTypes::LOGRIVER || type == RowTypes::TURTLESRIVER) {
			tileType = 2;
		}
		else if (type == RowTypes::ENDZONE) {
			tileType = i % 2;
			if (tileType == 1 && endZoneFirstSpawner) {
				spawners.back()->SetStartPosition(Vector2(i * 16, row * 16));
				spawners.back()->SetMinSpawnTime(1);
				spawners.back()->SetMaxSpawnTime(2);
				endZoneFirstSpawner = false;
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
	time -= TM->GetDeltaTime();

	for (int i = 0; i < spawners.size(); i++)
	{
		std::vector<GameObject*>* spawned = spawners[i]->Update();
		if (spawned != nullptr) {
			for (int i = 0; i < spawned->size(); i++) {
				objects.push_back(spawned->at(i));
			}
		}
	}

	for (int i = 0; i < tiles.size(); i++) {
		tiles[i]->Update();
	}

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
		if (objects[i]->GetTransform().position.x < -5 * 16 || objects[i]->GetTransform().position.x > 20 * 16 || (dynamic_cast<EndTileItem*>(objects[i]) != nullptr && dynamic_cast<EndTileItem*>(objects[i])->IsFinished())) {
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}

	if (player->FinishedDeathAnimation()) {
		if (lives > 0) {
			player->Respawn(Vector2(RM->windowWidth / 2 - 8, RM->windowHeight - 32));
			lives--;
		}			
		else {
			//GAme Over
		}
	}

	score = PM->GetScore();

	for (int i = 0; i < ui.size(); i++) {
		ui[i]->Update();
		if (i == 0) {
			dynamic_cast<TextObject*>(ui[i])->text->SetText("Score: " + std::to_string(score));
		}
		else if (i == 2) {
			dynamic_cast<TextObject*>(ui[i])->text->SetText("Lives: " + std::to_string(lives));
		}
		else if (i == 3) {
			dynamic_cast<TextObject*>(ui[i])->text->SetText("Time: " + std::to_string((int)time));
		}
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
	lives = 4;
	score = 0;
	time = 21;

	player = new Frog();
	
	player->SetPosition(Vector2(RM->windowWidth / 2 - 8, RM->windowHeight - 32));

	objects.push_back(player);
	
	for (int i = 0; i < 5; i++) {
		endPosition[i] = new bool(false);
	}

	LoadLevelFromFile("./resources/level.xml");

	TextObject* scoreUI = new TextObject("Score: " + std::to_string(score), Vector2(0, 0));
	ui.push_back(scoreUI);

	TextObject* highScore = new TextObject("HighScore: 0", Vector2(80, 0));
	ui.push_back(highScore);

	TextObject* liveUI = new TextObject("Lives: " + std::to_string(lives), Vector2(0, RM->windowHeight - 16));
	ui.push_back(liveUI);

	TextObject* timeUI = new TextObject("Time: " + std::to_string(time), Vector2(80, RM->windowHeight - 16));
	ui.push_back(timeUI);

	AM->LoadMusic("background");
	AM->LoadSFX("jump");

	AM->PlayMusic("background");
}

void GameplayScene::OnExit()
{
	AM->UnloadMusic("background");
	AM->UnloadSFX("jump");
}
