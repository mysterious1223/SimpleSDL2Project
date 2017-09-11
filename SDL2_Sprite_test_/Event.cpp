#include "Event.h"


Event::Event()
{}
Event::~Event()
{
	if (e != NULL)
	{
		delete e;
	}

}
const SDL_Event* Event::getEvent() const
{

	return e;
}

void Event::ListenForEvents()
{
	SDL_PollEvent(e);

	if (e->type == SDL_KEYDOWN)
	{
		
		KeyBoardState = ListenForKeyPress();

	}
	if (e->type == SDL_KEYUP)
	{
		KeyBoardState = 0;
	}
	
}
int Event::ListenForKeyPress()
{
	// add keyboard events
	switch (e->key.keysym.sym)
	{
	

	case SDLK_w:
		printf("up \n");
		return 1;
		break;
	case SDLK_s:
		printf("down \n");
		return 2;
		break;
	case SDLK_a:
		printf("left \n");
		return 3;
		break;
	case SDLK_d:
		printf("right \n");
		return 4;
		break;

	

	}


}