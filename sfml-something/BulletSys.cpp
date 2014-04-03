#include "BulletSys.h"



BulletSys::BulletSys()
{

}

void BulletSys::shootBullet(const RenderWindow &window, const Time& deltaTime, const TextureLoader& tl, EnemySys& enemySys)
{
	float delta = deltaTime.asSeconds()*50;

	float SHOOT_INTERVAL = 0.1f;
	float SHOTGUN_INTERVAL = 0.05f;

	if( delta > 1)
	{
		SHOTGUN_INTERVAL*=delta;
		SHOTGUN_INTERVAL*=delta;
	}
	
	shoot_switch = false;
	shoot_shotgun_switch = false;

	if(shoot_clock.getElapsedTime().asSeconds()>=SHOOT_INTERVAL)
	{
	checkBullet(window);
	
	std::vector<Enemy*>temp;
	temp = enemySys.getVect();

	for(int i = 0; i < temp.size();i++)
	{
		if(temp[i]->type == 'n')
		{

			if(shoot_clock.getElapsedTime().asSeconds()>=SHOOT_INTERVAL && checkSize())
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation(),tl,1));
			shoot_switch = true;
		
		}

		if(temp[i]->type == 's')
		{

		if(shoot_clock_shotgun.getElapsedTime().asSeconds()>=SHOTGUN_INTERVAL && checkSize())
		{
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation(),tl,0.8));
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation()+5,tl,0.8));
			bullet_vector.push_back(Bullet(temp[i]->getPosition(),temp[i]->getRotation()-5,tl,0.8));
			shoot_shotgun_switch = true;
		}
		}
	}

if(shoot_switch)
shoot_clock.restart();

if(shoot_shotgun_switch)
shoot_clock_shotgun.restart();
	
	//std::cout << "Bang" << std::endl;	
	//std::cout << bullet_vector.size() << std::endl;
	
	}

	std::vector<Bullet>::iterator it = bullet_vector.begin();

	while(it != bullet_vector.end())
	{
		(*it).move(deltaTime);
		it++;
	}
	
}

void BulletSys::checkPlayerCollision(Player &player)
{
	if(collisionClock_01.getElapsedTime().asMilliseconds() > 0.05f)
	{
	bullet_it = bullet_vector.begin();

	while(bullet_it!=bullet_vector.end())
	{
		if(player.getBoundingFloatRect().contains(bullet_it->getPosition()) && player.godMode == false)
			bullet_it->hitWarn();

			bullet_it++;
		
	}
	collisionClock_01.restart();
	}
}

bool BulletSys::checkSize()
{
	if( bullet_vector.size()>700)
		{
			bullet_it = bullet_vector.begin();
			bullet_it = bullet_vector.erase(bullet_it);
			return false;
		}
	else return true;
	
}

void BulletSys::init(std::vector<Tile>still_objects)
{
	still_vector = still_objects;
	//std::cout << still_vector.size();
}

void BulletSys::checkBullet(const RenderWindow &window)
{
	
	bullet_it = bullet_vector.begin();

	bool something_happened = false;

	while(bullet_it != bullet_vector.end())
	{	
		if((*bullet_it).getPosition().x > window.getSize().x || (*bullet_it).getPosition().x < 0)
		{	

			bullet_it = bullet_vector.erase(bullet_it);
			something_happened = true;

		}
		else if((*bullet_it).getPosition().y > window.getSize().y || (*bullet_it).getPosition().y < 0)
		{
		
			bullet_it = bullet_vector.erase(bullet_it);
			something_happened = true;
		}
		else
		{
			bullet_it++;
		}
	}

	if(something_happened)
	{
		bullet_vector.shrink_to_fit();
	}
}

void BulletSys::drawBullet(RenderWindow &window)
{
	bullet_it = bullet_vector.begin();

	while(bullet_it != bullet_vector.end())
	{	
		(*bullet_it).draw(window);
		bullet_it++;
	}
}

void BulletSys::checkStillCollision()
{
	if(collisionClock_02.getElapsedTime().asSeconds()>0.2f)
	{
	bullet_it = bullet_vector.begin();
	still_it = still_vector.begin();
	bool something_happened = false;

	//std::cout << still_vector.size() << std::endl;

	while(still_it != still_vector.end())
	{	
		something_happened = false;
	
		bullet_it = bullet_vector.begin();

		while(bullet_it != bullet_vector.end())
		{

			if(still_it->getBounds().intersects(bullet_it->getGlobalBounds()))
				{

					bullet_it = bullet_vector.erase(bullet_it);
					something_happened = true;
				}
			else
				bullet_it++;
		}
		
	still_it++;
	}
	if(something_happened)
	bullet_vector.shrink_to_fit();

	collisionClock_02.restart();
	}
}

void BulletSys::renewBullets(std::vector<Bullet> *bv)
{
	bullet_vector = *bv;
}

BulletSys::~BulletSys(void)
{
}
