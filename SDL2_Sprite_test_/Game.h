#pragma once
#ifndef GAME_H 
#define GAME_H
#include "Display.h"
#include "Event.h"
#include "Character.h"

class Game
{
public:
	// game object will have draw function


	// init, loop, kill
	Game();

	~Game();

	void init();
	void loop();
	void kill();


private:

	Display *myDisplay;
	Event *myEvent;
	Uint32 current_time, old_time;
	float fTime;
};


#endif