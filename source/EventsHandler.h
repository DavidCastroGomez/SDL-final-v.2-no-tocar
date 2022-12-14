#pragma once
#include "InputManager.h"
#include "RendererManager.h"

#define EH EventsHandler::GetInstance()

class EventsHandler
{
private: 
	static EventsHandler* instance;
public:
	static EventsHandler* GetInstance();
	void HandleEvents();
};

