#pragma once
#include <SDL_image.h>
#include <math.h>

// Sprite class which contains a texture, position, velocity, size, and functions for drawing it.

class Bullet
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;
	
public:
	SDL_Rect dst;

	// velocity (maybe not necessary for every sprite)
	float velY = 10;

	// constructors -- these are used when initializing an object
	Bullet();
	Bullet(SDL_Renderer* renderer, int x, int y);
	
	// destructor -- used when the object is to be removed from memory
	~Bullet();

	void update();
	void draw(SDL_Renderer* renderer);

	void cleanup();

	bool readyToDestroy() { return dst.y <= 0; }
	bool checkCollision(SDL_Rect r);
};