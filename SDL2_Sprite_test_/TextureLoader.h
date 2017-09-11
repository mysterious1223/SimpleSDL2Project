#pragma once
#ifndef TEXTURELOADER_H 
#define TEXTURELOADER_H
#include "STDSDL.h"

class Texture
{
public:



	Texture();
	~Texture();

	void setRenderer(SDL_Renderer*);
	bool LoadImage(std::string, int flag); // flag if we should query texture
	void setDimensions(int x,int y,int h,int w);
	SDL_Texture* getTexture();
	SDL_Rect getRect();


private:

	SDL_Texture* texture;
	SDL_Rect textureRect;
	SDL_Renderer* render;

};



#endif 