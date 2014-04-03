#pragma once
#include "Enemy.h"
#include "ShotgunEnemy.h"
#include <iostream>
class EnemySys
{
public:
	EnemySys(int amount, TextureLoader &tl);
	~EnemySys(void);
	void draw(RenderWindow& window);
	std::vector<Enemy*> getVect();
	void rotateLikeAMadCunt(const Time &dt);
	void spawnEnemy(Vector2f position);
	void spawnEnemyShotgun(Vector2f position);
private:
	std::vector<Enemy*>enemy_vector;
	std::vector<Enemy*>::iterator it;
	Sprite _enemySprite;
	
};

