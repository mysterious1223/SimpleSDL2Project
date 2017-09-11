#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Sprite.h"
#include "Physics.h"

class GameObject
{
public:
	//GameObject(std::string, SDL_Renderer*);


	virtual void createSprite(std::string, SDL_Renderer*) = 0;
	virtual void instantiate(float x, float  y, float  scaleH, float  scaleW)=0;
	
	virtual void draw(float  x, float  y)=0;
	virtual void draw()=0;

	virtual void move(float  x, float  y)=0;
	virtual void kill()=0;
	virtual float  getX()=0;
	virtual float  getY()=0;
	virtual float  checkDistanceToObject(GameObject*)=0;
	virtual void setVelocity(float, float)=0;
	virtual void setRigid(bool) = 0;

	virtual void setX(float)=0;
	virtual void setY(float)=0;
	//virtual	Physics *getPhysics() = 0;


protected:
	

};


#endif