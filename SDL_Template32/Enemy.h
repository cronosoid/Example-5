#pragma once
#include "Player.h"
#include <SDL_image.h>

class Enemy
{
	SDL_Texture* pEnemyTex = nullptr;
	SDL_Rect src;
	SDL_Rect dst;

public:

	SDL_Rect getRect();
	// constructors -- these are used when initializing an object
	Enemy();
	Enemy(SDL_Renderer* renderer);
	

	// destructor -- used when the object is to be removed from memory
	~Enemy();

	void draw(SDL_Renderer* renderer);

	void cleanup();

};

