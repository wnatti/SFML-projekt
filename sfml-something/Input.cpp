#include "Input.h"
#include <iostream>
using namespace std;

static const float PII = 3.141592f;

Input::Input(void)
{
}


Vector2f Input::movePlayer(const Time& dt,Player& p,TileSys &ts)
{
	Vector2f movement(0,0);

	if(!checkMovement(p,ts))
	{
	float delta = dt.asSeconds()*100;
	
	if(Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.x = (cos(p.getRotation()*PII/180)*delta*2);
		movement.y = (sin(p.getRotation()*PII/180)*delta*2);
	}
	if(Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.x = (cos(p.getRotation()*PII/180)*-delta);
		movement.y = (sin(p.getRotation()*PII/180)*-delta);
	}

	if(Keyboard::isKeyPressed(Keyboard::Left))
			movement.x -=delta;
			//movement.x -=1;
		

	if(Keyboard::isKeyPressed(Keyboard::Right))
			movement.x+=delta;
			//movement.x+=1;
	

	if(Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down))
			movement.y-=delta;
			//movement.y-=1;


		
	if(Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Up))
			movement.y+=delta;
			//movement.y+=1;
	
		p.lastMovement = movement;
		return movement;
	
	}

	else
		return -p.lastMovement;
	
}

bool Input::checkMovement(Player& p,TileSys &ts)
{
	std::vector<Tile> tvec = ts.getTVector();
	std::vector<Tile>::iterator itt;
	itt = tvec.begin();

	while(itt!=tvec.end())
	{
		if(p.getBoundingFloatRect().intersects((itt)->getBoundingFloatRect()) && p.godMode == false)
			{
				return true;
			}
		else
			itt++;
			
	}
	return false;

}

bool Input::rotatePlayer()
{

	/*if(Keyboard::isKeyPressed(Keyboard::A))
	{
		rotation = -5*delta;
	}
	if(Keyboard::isKeyPressed(Keyboard::D))
	{
		rotation = 5*delta;
	}*/

	
	if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			return true;
		}
	
	else
		return false;

	
}

bool Input::dodgeJump()
{
	if(Keyboard::isKeyPressed(Keyboard::Q))
		return true;
	else
		return false;
}

Input::~Input(void)
{
}
