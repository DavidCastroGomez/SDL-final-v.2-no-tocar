#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include <assert.h>

#define SM SceneManager::GetInstance()

class SceneManager {
public:
	//Agregation -> Scene
	void AddScene(std::string name, Scene* s);
	//Getters
	Scene* GetScene(std::string name);
	Scene* GetCurrentScene();
	//Setters
	void SetScene(std::string name);

	static SceneManager* GetInstance();
private:
	SceneManager();
	static SceneManager* instance;
	std::map<std::string, Scene*> scenes;
	Scene* currentScene;
};


