#pragma once
#ifndef DISPLAY_H 
#define DISPLAY_H
#include "STDSDL.h"

class Display
{
public:

	Display(int& , int& , std::string &);
	~Display();


	


	SDL_Window* getWindow();
	SDL_Renderer* getRenderer(); // error?

	void clearScreen();
	void presentScreen();


private:
	SDL_Window *window = NULL;
	SDL_Renderer *render = NULL;

	//int height, width; 
	//std::string title;

};


#endif