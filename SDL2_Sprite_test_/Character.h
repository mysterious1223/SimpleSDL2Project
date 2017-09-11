#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Physics.h"

class Character : public GameObject
{
public:
	Character(std::string, SDL_Renderer*);
	~Character();

	
	void instantiate(float x, float y, float scaleH, float scaleW);

	void draw(float  x, float  y);
	void draw();

	void move(float  x, float y);
	float getX();
	float getY();

	//inline bool checkIfRigid() { return rigid; }
    Physics *getPhysics() { return physics; }

	void kill();
	void setVelocity(float, float);
	void setRigid(bool);
	float checkDistanceToObject(GameObject*);


	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void idle();


	void setX(float);
	void setY(float);
	
	float* s_h, *s_w;
	SDL_Rect getCollisionBox() { return sprite->getScaleRect(); }


private:
	void createSprite(std::string, SDL_Renderer*);
	float  myX;
	float  myY;
	Sprite *sprite;

	float velocity;

	int d;
	int f;
	int l;
	int r;

	float fTime;

	Physics *physics;
	

};


#endif