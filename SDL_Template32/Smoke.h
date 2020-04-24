#pragma once
#include <SDL_image.h>


class Smoke
{
	SDL_Texture* pSpriteTex = nullptr;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_Renderer* renderer;

	//Animation related variables

	//Number of columns
	int numColumns = 8;

	//Which frame we are displaying
	int displayFrame = 0;

	//How mnay frames there are
	int frameCount = 64;


	/*
	Total size of the image: 2048x2048
	Each frame size: 256x256
		Width: Total Width / Column Count; 2048/8 = 256 pixels
		Height: Total Height / Row Count; 2048/8 = 256 pixels
	*/
	int frameWidth = 256;
	int frameHeight = 256;

	int targetWidth = 128;
	int targetHeight = 128;




public:
	Smoke() { };
	Smoke(SDL_Renderer* renderer, int posX, int posY);


	~Smoke() {};

	bool animate();
	void cleanup();
};



