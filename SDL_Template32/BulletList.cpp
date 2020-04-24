#include "BulletList.h"

BulletList::BulletList(){}
BulletList::~BulletList(){}

void BulletList::AddBullet(SDL_Renderer* renderer, int x, int y)
{
	bulletArray.emplace_back(Bullet(renderer, x, y));
	SoundManager::Instance()->playSound("pew", 0);
}

void BulletList::UpdateBullets(SDL_Renderer* renderer, Enemy obstacle)
{
	for (auto it = bulletArray.begin(); it != bulletArray.end();) {
		it->update();
		if (it->checkCollision(obstacle.getRect()))
		{
			TextureManager::Instance()->AddSmoke(renderer, it->dst.x, it->dst.y);
			it = bulletArray.erase(it);
		}
		else
		{
			it->draw(renderer);
			++it;
		}
	}
}