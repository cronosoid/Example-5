#include "Smoke.h"
#include <iostream>
#include <math.h>

Smoke::Smoke(SDL_Renderer* renderer, int dstX, int dstY)
{
	this->renderer = renderer;


	pSpriteTex = IMG_LoadTexture(renderer, "explosion.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;
	src.w = frameWidth;
	src.h = frameHeight;


	dst.x = dstX - targetWidth / 2;
	dst.y = dstY - targetHeight / 2;
	dst.w = targetWidth;
	dst.h = targetHeight;

}

bool Smoke::animate()
{
	if (displayFrame == frameCount)
	{
		return false;
	}


	src.x = (displayFrame % numColumns) * frameWidth;
	src.y = (displayFrame / numColumns) * frameWidth;

	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);

	//we skip 1 frame because the animation has a higher framerate (it appears too slow)
	displayFrame += 2;
	if (displayFrame == frameCount)
	{
		cleanup();
		return false;
	}

	return true;
}

void Smoke::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

