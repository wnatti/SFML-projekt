#pragma once
#include "Bullet.h"
#include "SFML\Graphics.hpp"
#include "Enemy.h"
#include "EnemySys.h"
#include "TileSys.h"
#include "Player.h"

class BulletSys
{
public:
	BulletSys();
	~BulletSys(void);
	void shootBullet(const RenderWindow &window,const Time& deltaTime,const TextureLoader& tl, EnemySys& enemySys);
	void drawBullet(RenderWindow &window);
	std::vector<Bullet>& getBVector(){return bullet_vector;}
	void renewBullets(std::vector<Bullet> *bv);
	bool checkSize();
	void checkStillCollision();
	void checkPlayerCollision(Player &player);
	void init(std::vector<Tile>still_objects);
private:
	void checkBullet(const RenderWindow &window);
	std::vector<Bullet>bullet_vector;
	std::vector<Bullet>::iterator bullet_it;
	Clock shoot_clock;
	Clock shoot_clock_shotgun;
	bool shoot_switch;
	bool shoot_shotgun_switch;
	int test;
	std::vector<Tile>still_vector;
	std::vector<Tile>::iterator still_it;
	Clock collisionClock_01;
	Clock collisionClock_02;
};

