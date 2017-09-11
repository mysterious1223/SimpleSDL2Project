#include "Display.h"



Display::Display(int& h, int& w, std::string& t)
{

	bool go = false;

	if (SDL_Init(SDL_INIT_VIDEO)<2)
	{
		//printf(t.c_str());
		window = SDL_CreateWindow(t.c_str(), 100,100, w, h, SDL_WINDOW_SHOWN);
		go = true;
	}
	else
	{
		printf("window failed to initialize");
	}

	if (go)
	{
		render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		//go = true;
	}
	if (render == NULL) printf("render failed");





}


Display::~Display()
{
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);

	window = NULL;
	render = NULL;


}
SDL_Window* Display::getWindow()
{
	return window;
}
SDL_Renderer* Display::getRenderer()
{

	return render;
}
void Display::clearScreen()
{
	SDL_RenderClear(render);

}
void Display::presentScreen()
{

	SDL_RenderPresent(render);
}