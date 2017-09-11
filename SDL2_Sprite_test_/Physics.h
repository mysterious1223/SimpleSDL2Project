#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include "STDSDL.h"
#include "GameObject.h"
class Physics
{
public:
	Physics();
	~Physics();
	// solidify objects

	
	bool CheckForCollision(SDL_Rect rect1, SDL_Rect rect2);



	void stopObject();
	bool isRigid;


private:
	//GameObject *myObject;


};



#endif