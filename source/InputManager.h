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

class InputManager {
private:
	std::unordered_map<Sint32, KeyState> keys;
	int mouseX, mouseY;
	bool quitEvent;

public:
	InputManager() : quitEvent(false), mouseX(0), mouseY(0){};
	void Listen();
	bool CheckKeyState(Sint32 key, KeyState state);
	int GetMouseX();
	int GetMouseY();
	bool GetQuitEvent();
};