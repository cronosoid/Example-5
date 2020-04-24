#include "Enemy.h"

SDL_Rect Enemy::getRect()
{
	return dst;
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pEnemyTex, &src, &dst);
}

void Enemy::cleanup()
{
}

Enemy::Enemy(SDL_Renderer* renderer)
{
	pEnemyTex = IMG_LoadTexture(renderer, "grunt-0.png");

	SDL_QueryTexture(pEnemyTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	dst.x = 590;
	dst.y = 500;
	dst.w = 70;
	dst.h = 70;
}

