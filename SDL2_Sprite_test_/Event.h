#pragma once
#ifndef EVENT_H 
#define EVENT_H

#include "STDSDL.h"

class Event
{

public:

	//enum key_states {up, down, left, right};


	Event();

	~Event();


	void ListenForEvents(); // our loop

	

	const SDL_Event* getEvent() const;
	int KeyBoardState = 0;

private:
	// later add keyboard events
	int ListenForKeyPress();
	SDL_Event* e = new SDL_Event();

	

	//key_states currKeystate;

};

#endif