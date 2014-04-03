#include "ShotgunEnemy.h"


ShotgunEnemy::ShotgunEnemy()
{
	Enemy::Enemy();
	type = 's';
}

ShotgunEnemy::ShotgunEnemy(TextureLoader &tl, Vector2f position)
{
	Enemy::Enemy(tl, position);
	type = 's';
}

ShotgunEnemy::ShotgunEnemy(Sprite sprite, Vector2f position)
{
	Enemy::Enemy(sprite,position);
	type = 's';
}
ShotgunEnemy::~ShotgunEnemy(void)
{
}
