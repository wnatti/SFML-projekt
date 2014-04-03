#pragma once
#include "Enemy.h"
class ShotgunEnemy : public Enemy
{
public:
	ShotgunEnemy(TextureLoader& tl, Vector2f position);
	~ShotgunEnemy(void);
	ShotgunEnemy();
	ShotgunEnemy(Sprite sprite, Vector2f position);
private:
	char type;
};

