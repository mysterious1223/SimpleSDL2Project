#pragma once
#ifndef SPRITE_H 
#define SPRITE_H
#include "STDSDL.h"
#include "TextureLoader.h"
#include "Display.h"

class Sprite
{
public:
	Sprite(SDL_Renderer*);
	~Sprite();

	// instantiate sprite

	void CreateSprite(std::string);
	void AnimatePosition(int pos);
	void DrawSprite();

	void moveSprite(float& x, float& y);
	void setScale(float& h, float& w);
	void destroySprite();
	void animate(int frame_s, int& curr_iter , float);
	SDL_Rect getScaleRect() { return spriteScale; }


private:

	SDL_Renderer* render;
	Texture* texture;
	SDL_Rect spriteScale;

	
	float xPos, yPos;
	float hScale, wScale;

	float mappingX[16] = { 0,32,64,96,
						0,32,64,96 ,
						0,32,64,96 ,
						0,32,64,96 };
	float mappingY[16] = { 0,0,0,0,
						48,48,48,48,
						96,96,96,96,
						144,144,144,144};

};


#endif
