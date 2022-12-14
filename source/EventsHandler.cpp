#include "EventsHandler.h"

EventsHandler* EventsHandler::instance = nullptr;

EventsHandler* EventsHandler::GetInstance()
{
	if (instance == nullptr) {
		instance = new EventsHandler();
	}
	return instance;
}

void EventsHandler::HandleEvents()
{
	SDL_Event evt;

	while (SDL_PollEvent(&evt)) {
		if (evt.type == SDL_QUIT) {
			IM->SetQuitEvent(true);
		}
		else if (evt.type == SDL_KEYDOWN) {
			IM->GetKeys()->at(evt.key.keysym.sym) = (KeyState)(DOWN | PRESSED);
		}
		else if (evt.type == SDL_KEYUP) {
			IM->GetKeys()->at(evt.key.keysym.sym) = (KeyState)(UP | RELEASED);
		}
		else if (evt.window.event == SDL_WINDOWEVENT_RESIZED) {
			SDL_RenderSetScale(RM->GetRenderer(), RM->windowWidth / evt.window.data1, RM->windowHeight / evt.window.data2);
			SDL_RenderPresent(RM->GetRenderer());
		}
	}
}
