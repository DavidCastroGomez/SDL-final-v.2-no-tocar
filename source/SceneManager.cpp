#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager() {

}

//Adds a scene to the scene map.
void SceneManager::AddScene(std::string name, Scene* s)
{
	scenes.emplace(name, s);
}

SceneManager* SceneManager::GetInstance() {
	if (instance == nullptr) {
		instance = new SceneManager();
	}
	return instance;
}

Scene* SceneManager::GetScene(std::string name) {
	auto scene = scenes.find(name);
	bool sceneFound = scene != scenes.end();
	return sceneFound ? scenes[name] : nullptr;
}

//Returns a pointer to the current scene
Scene* SceneManager::GetCurrentScene() {
	return currentScene;
}

void SceneManager::SetScene(std::string name) {
	auto scene = scenes.find(name);

	bool sceneFound = scene != scenes.end();

	//Stop code to warn dev
	assert(sceneFound);
	if (sceneFound) {
		if (currentScene != nullptr) {
			currentScene->OnExit();
		}			
		currentScene = scene->second;
		currentScene->OnEnter();
	}
}

//template <class S> S* SceneManager::GetScene()
//{
//	auto scene = scenes.find(typeid(S));
//
//	bool sceneFound = scene != scenes.end();
//
//	return sceneFound ? dynamic_cast<S*>(scene->second) : nullptr;
//}