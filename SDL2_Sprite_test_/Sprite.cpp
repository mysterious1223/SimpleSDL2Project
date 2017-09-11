#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer)
{
	render = renderer;
	texture = new Texture;

	
}
Sprite::~Sprite()
{

	if (render != NULL)
	{
		delete render;
	}
	if (texture != NULL)
	{
		delete texture;
	}
}
void Sprite::CreateSprite(std::string filePath)
{
	texture->setRenderer(render);
	texture->LoadImage(filePath.c_str(),0);
	spriteScale.h = 48; spriteScale.w = 30;

	

}

void Sprite::AnimatePosition(int pos)
{
	// x can be column and y can be rows
	// 0 - 3 
	



	spriteScale.x = mappingX[pos-1];
	spriteScale.y = mappingY[pos-1];

	
}

void Sprite::DrawSprite()
{
	texture->setDimensions(xPos,yPos, hScale, wScale);
	//printf("%d, %d \n", spriteScale.x, spriteScale.y);
	SDL_RenderCopy(render, texture->getTexture(),&spriteScale, &texture->getRect());
}
void Sprite::moveSprite(float& x, float& y)
{
	xPos =  x;
	yPos =  y;

}
void Sprite::setScale(float& h, float& w)
{
	hScale = h;
	wScale = w;
}
void Sprite::animate(int frame_s, int& curr_iter, float fTime)
{
	// check iteration for number of steps the switch animation

	int start = frame_s;

	if (curr_iter == 0)
	{
		AnimatePosition(frame_s);
	}
	if (curr_iter == 150) // 150
	{
		AnimatePosition(frame_s + 1);
	}
	if (curr_iter == 300 ) // 300
	{
		AnimatePosition(frame_s + 2);
	}
	if (curr_iter == 500 ) // 500
	{
		AnimatePosition(frame_s + 3);
	}
	if (curr_iter >= 700 ) curr_iter = 0; //700


}
void Sprite::destroySprite()
{
	SDL_DestroyTexture(texture->getTexture());
	
}