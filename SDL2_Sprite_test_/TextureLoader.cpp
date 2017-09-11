#include "TextureLoader.h"

Texture::Texture()
{
	texture = NULL;
	render = NULL;
}
Texture::~Texture()
{

	if (texture != NULL)
	{
		delete texture;
	}
	if (render != NULL)
	{
		delete render;
	}
}
SDL_Texture* Texture::getTexture()
{
	return texture;
}
SDL_Rect Texture::getRect()
{

	return textureRect;
}
void Texture::setRenderer(SDL_Renderer* renderer)
{
	render = renderer;
}
void Texture::setDimensions(int x, int y, int h, int w)
{
	textureRect.x = x;
	textureRect.y = y;
	textureRect.h = h;
	textureRect.w = w;
}
bool Texture::LoadImage(std::string filePath, int flag)
{

	if (render != NULL)
	{
	
		texture = IMG_LoadTexture(render, filePath.c_str());
		if (texture == NULL)
		{
			printf("image not found");
		}
		if (flag == 1)
		{
			//query texture

		}

		return true;
	}
	return false;
}
