/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO

#include "Game.h"

int main(int argc, char* args[])
{
	
	// Display class = window / renderer 
	// Event class = SDL_Event
	// Game
	// GameObject class = Virtual inheritance
	// Sprite class
	// for now
	Game *game = new Game;

	game->init();

	game->loop();








	return 0;
}

/*
bool quit = false;

SDL_Init(SDL_INIT_VIDEO);

SDL_Window* window = NULL;

window = SDL_CreateWindow("My first RPG", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);// add flags to change windows option | you can ex: SDL_WINDOW_RESIZABLE

if (window == NULL)
{
printf("error window failed");
return 0;
}

SDL_Renderer* render = NULL;

render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);





SDL_Event* e = new SDL_Event();



SDL_Texture* gary_image = NULL;
//SDL_Surface* gary_surface = NULL;

//gary_surface = SDL_LoadBMP("C:/Users/ksingh/Documents/Visual Studio 2015/Projects/SDL_RPG_TUTORIAL/Debug/wolf2.bmp"); //get an image

//gary_image = SDL_CreateTextureFromSurface(render, gary_surface);

gary_image = IMG_LoadTexture(render, "C:/Users/ksingh/Documents/Visual Studio 2015/Projects/SDL_RPG_TUTORIAL/Debug/wolf2.bmp");


SDL_Rect gary_rect;
gary_rect.x = 10;
gary_rect.y = 50;
gary_rect.w = 250;
gary_rect.h = 250;


SDL_Texture* bob_image = NULL;
SDL_Surface* bob_surface = NULL;

bob_surface = SDL_LoadBMP("C:/Users/ksingh/Documents/Visual Studio 2015/Projects/SDL_RPG_TUTORIAL/Debug/bob.bmp");

bob_image = SDL_CreateTextureFromSurface(render,bob_surface);
SDL_Rect bob_rect;

bob_rect.x = 300;
bob_rect.y = 50;
bob_rect.h = 250;
bob_rect.w = 250;


SDL_Texture* grass_image = NULL;
SDL_Surface* grass_surface = NULL;

grass_surface = SDL_LoadBMP("C:/Users/ksingh/Documents/Visual Studio 2015/Projects/SDL_RPG_TUTORIAL/Debug/Grass.bmp");

grass_image = SDL_CreateTextureFromSurface(render, grass_surface);
SDL_Rect grass_rect;

grass_rect.x = 0;
grass_rect.y = 0;
grass_rect.h = SCREEN_HEIGHT;
grass_rect.w = SCREEN_WIDTH;



if (gary_image == NULL)
{
printf("eerrrrro cant find gary \n");
}
if (bob_surface == NULL)
{
printf("eerrrrro cant find bob \n");
}

//grass_image = SDL_CreateTexture(render,);


int i = 0;

while (!quit && e->type != SDL_QUIT)
{
SDL_PollEvent(e);

//i++;

//if (i > 20) i = 0;


//grass_rect.w = i + SCREEN_WIDTH;

SDL_RenderClear(render);


SDL_RenderCopy(render, grass_image, NULL, &grass_rect);
SDL_RenderCopy(render, gary_image, NULL, &gary_rect);
SDL_RenderCopy(render, bob_image, NULL, &bob_rect);

SDL_RenderPresent(render);


}
SDL_DestroyWindow(window);

SDL_DestroyRenderer(render);

delete e;

*/