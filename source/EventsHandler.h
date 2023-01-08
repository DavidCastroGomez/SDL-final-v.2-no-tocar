#pragma once
#include "InputManager.h"
#include "RendererManager.h"
#include "AudioManager.h"

#define EH EventsHandler::GetInstance()

class EventsHandler
{
private: 
	static EventsHandler* instance;
public:
	static EventsHandler* GetInstance();
	void HandleEvents();
};

