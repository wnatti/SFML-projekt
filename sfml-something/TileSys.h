#pragma once
#include "Tile.h"
#include "Findiffer.h"
#include <algorithm>
#include <iostream>

class TileSys
{
public:
	TileSys(TextureLoader &tl);
	TileSys(){};
	virtual ~TileSys(void);
	void draw(RenderWindow& window);
	/*bool checkCollision(const Bullet &b);
	void eraseCollided(BulletSys &bs);*/
	std::vector<Tile>getTVector(){return tile_vector;}
	std::vector<Tile>tile_vector;
	std::vector<Tile>::iterator tile_it;
protected:
	//std::vector<Bullet>*bvec;
};