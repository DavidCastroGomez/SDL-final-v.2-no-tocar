#include <SDL.h>
#include <stdio.h>
#include "GameEngine.h"

int main(int argc, char* args[]) {
	GameEngine game;
	game.Init();
	game.Run();
	game.Quit();
	return 0;
}