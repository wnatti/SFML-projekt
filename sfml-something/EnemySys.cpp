#include "EnemySys.h"


EnemySys::EnemySys(int amount, TextureLoader &tl)
{
	_enemySprite = tl.getSprite("head");
	while(amount > 0)
	{
		enemy_vector.push_back(new Enemy(tl,Vector2f(400,10*amount)));
		--amount;
	}
}

void EnemySys::rotateLikeAMadCunt(const Time &dt)
{
	it = enemy_vector.begin();
	float delta = dt.asSeconds()*100;
	while(it!=enemy_vector.end())
	{
		(*it)->rotate(delta);
		it++;
	}
}
void EnemySys::draw(RenderWindow& window)
{
	it = enemy_vector.begin();
	
	while(it!= enemy_vector.end())
	{
		(*it)->draw(window);
		it++;
	}
}

void EnemySys::spawnEnemy(Vector2f position)
{
	enemy_vector.push_back(new Enemy(_enemySprite,position,'n'));
}

void EnemySys::spawnEnemyShotgun(Vector2f position)
{
	enemy_vector.push_back(new Enemy(_enemySprite,position,'s'));
}

std::vector<Enemy*> EnemySys::getVect()
{
	return enemy_vector;
}

EnemySys::~EnemySys(void)
{
}
