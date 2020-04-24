#include "Player.h"
#include <iostream>
#include "Enemy.h"

//constructor
Player::Player()
{
}

//constructor
Player::Player(SDL_Renderer* renderer, const char* filename,
	int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	dst.x = 300;
	dst.y = 500;
	dst.w = w;
	dst.h = h;
}

//constructor
Player::Player(SDL_Renderer* renderer, const char* filename,
	int srcX, int srcY, int srcW, int srcH,
	int dstX, int dstY, int dstW, int dstH)
{
	pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = srcX;
	src.y = srcY;
	src.w = srcW;
	src.h = srcH;


	dst.x = dstX;
	dst.y = dstY;
	dst.w = dstW;
	dst.h = dstH;
}


//destructor
Player::~Player()
{
}

void Player::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

void Player::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}


void Player::moveBy(int x, int y)
{
	dst.x += x * speed;
	dst.y += y * speed;
}

void Player :: checkBounds()
{
		// check right boundary
		if (dst.x > 800 - dst.w)
		{

			setPosition(800 - dst.w ,dst.y);
		}

		// check left boundary
		if (dst.x < 0)
		{

			setPosition(0, dst.y);
		}

		if (dst.y < 450)
		{
			setPosition(dst.x, 450);
		}
	
		if (dst.y > 600 - dst.h)
		{
			
			setPosition(dst.x, 600 - dst.h);
		}
}

void Player::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}

void Player :: checkCollision(Enemy obstacle)
{
	SDL_Rect r = obstacle.getRect();
	
		if(r.x < dst.x + dst.w &&
		r.x + r.w > dst.x &&
		r.y < dst.y + dst.h &&
		r.h + r.y > dst.y)
		{
			dst.x = r.x - dst.w * 0.9;
		}
}