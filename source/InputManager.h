#pragma once
#include <SDL.h>
#include <unordered_map>

enum KeyState{ 
	UNDEFINED = 1, //UNDEFINED: Code tries to acces key but it hasn't been registered yet
	DOWN = 2,	//Frame that the key is pressed
	PRESSED = 4,	//The key is pressed
	UP = 8,		//Frame that the key is relesased
	RELEASED = 16	//Released
};

#define IM InputManager::GetInstance()

class InputManager {
private:
	std::unordered_map<Sint32, KeyState> keys;
	int mouseX, mouseY;
	bool clicked;
	bool quitEvent;
	InputManager() : quitEvent(false), mouseX(0), mouseY(0), clicked(false){};
	static InputManager* instance;
public:
	static InputManager* GetInstance();
	void Listen();
	bool CheckKeyState(Sint32 key, KeyState state);
	int GetMouseX();
	int GetMouseY();
	bool GetQuitEvent();
	void SetClick(bool clicked);
	bool GetClicked();
	std::unordered_map<Sint32, KeyState>* GetKeys();
	void SetQuitEvent(bool b);
};