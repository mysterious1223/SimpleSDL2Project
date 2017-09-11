#include "Game.h"

Game::Game()
{
	myDisplay = NULL;
	myEvent = NULL;


}
Game::~Game()
{
	kill();

}
void Game::init()
{

	std::string t = "myTitle";
	int h = 720;
	int w = 720;
	myDisplay = new Display(h, w, t);

	myEvent = new Event;


}
void Game::loop()
{
	int mode = 0;

	Character *player = new Character("C:/Users/ksingh/Documents/Visual Studio 2015/Projects/SDL2_Sprite_test_/Debug/spriteSheet.png",myDisplay->getRenderer());
	Character *AI = new Character("C:/Users/ksingh/Documents/Visual Studio 2015/Projects/SDL2_Sprite_test_/Debug/aiSheet.png", myDisplay->getRenderer());


	

	// We need an gameobject array so we can do things more efficently

	player->instantiate(200,10,50.55,29);
	AI->instantiate(210, 50, 50.55, 29);
	
	current_time = SDL_GetTicks();


	Physics physics;


	while (myEvent->getEvent()->type != SDL_QUIT)
	{
		// Have a check game objects for collision loop, then use the offset to throught the object back
		// ~ add fTime to animations to create a frame rate independent transition
		old_time = current_time;
		current_time = SDL_GetTicks();
		fTime = (current_time - old_time) / 100.0f;
		myEvent->ListenForEvents();

		player->setVelocity(5,fTime);
		AI->setVelocity(5, fTime);
		// use frames for animation

		myDisplay->clearScreen();
	
		if (physics.CheckForCollision(player->getCollisionBox(), AI->getCollisionBox()))
		{
			printf("collision\n");

		}
		if (myEvent->KeyBoardState == 1)
		{
			player->moveUp();
			
			
		}
		if (myEvent->KeyBoardState == 2)
		{
			player->moveDown();

			
		}
		if (myEvent->KeyBoardState == 3)
		{
			player->moveLeft();
		
		}
		if (myEvent->KeyBoardState == 4)
		{
			player->moveRight();
			
		}
	
		if (mode == 0)
		{
			if (AI->getX() <= 250)
			{

				AI->moveRight();
				//printf("+ AI MOVE RIGHT \n");
			}
			else
			{
				mode = 1;

			}
		}
		if (mode == 1)
		{

			if (AI->getY() <= 125)
			{
				AI->moveDown();
				//printf("+ AI MOVE DOWN \n");

			}
			else
			{
				mode = 2;
			}

		}
		if (mode == 2)
		{
			if (AI->getX() > 100)
			{
				AI->moveLeft();
				//printf("+ AI MOVE LEFT \n");
			}
			else
			{
				mode = 3;
			}
		}
		if (mode == 3)
		{
			if (AI->getY() >= 50)
			{
				AI->moveUp();
				//printf("+ AI MOVE UP \n");
			}
			else mode = 0;
		}
	
	


		player->draw();

		// when AI kill is called this function will generate an error
		// store game objects in a array? so we can easily delete and add data or objects

		AI->draw();

		myDisplay->presentScreen();
		// create an ai script class to control AI
		//system("CLS");
	}

}
void Game::kill()
{
	delete myDisplay;
	delete myEvent;
}