#include "Character.h"


Character::Character(std::string file, SDL_Renderer* ren)
{
	sprite = NULL;
	createSprite(file, ren);
	d = 0;
	f = 0;
	//physics = new Physics(this);
}
Character::~Character()
{
	delete sprite;
}
void Character::createSprite(std::string file, SDL_Renderer* render)
{
	sprite = new Sprite(render);
	sprite->CreateSprite(file);
	
}
void Character::instantiate(float  x, float y, float scaleH, float scaleW)
{
	myX = x;
	myY = y;
	sprite->moveSprite(myX, myY);

	s_h = &scaleH;
	s_w = &scaleW;

	sprite->setScale(scaleH, scaleW);
}
void Character::draw(float x, float y)
{
	sprite->DrawSprite();
	sprite->moveSprite(x,y);
}
void Character::draw()
{
	sprite->DrawSprite();



	// animate
	//sprite->AnimatePosition(1);
}
void Character::move(float x, float y)
{
	myX = myX  + x;
	myY = myY  + y;
	sprite->moveSprite(myX, myY);
}
float  Character::checkDistanceToObject(GameObject* object)
{
	float x1 = this->getX();
	float y1 = this->getY();

	float x2 = object->getX();
	float y2 = object->getY();

	float distance = 0;
	distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	


	return distance;
}
void Character::setRigid(bool isRigid)
{
	physics->isRigid = isRigid;
}
void Character::setX(float x)
{
	myX = x;
	
}
void Character::setY(float y)
{
	myY = y;
}
float Character::getX()
{
	return myX;

}
float Character::getY()
{
	return myY;
}
void Character::setVelocity(float v, float f)
{
	fTime = f;
	velocity = v*f;
}
void Character::kill()
{
	sprite->destroySprite();
	delete sprite;
}
void Character::moveUp()
{
	move(0, -1 * velocity);
	//sprite->AnimatePosition(16);
	f++;
	sprite->animate(13, f, fTime);
}
void Character::moveDown()
{
	//sprite->AnimatePosition(1);
	move(0, velocity);

	d++;
	sprite->animate(1, d, fTime);

}
void Character::moveLeft()
{
	move(-velocity,0);
	l++;
	sprite->animate(5, l, fTime);
}
void Character::moveRight()
{
	move(velocity, 0);
	r++;
	sprite->animate(9, r, fTime);
}
