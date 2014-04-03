#pragma once
#include "GameObject.h"
#include "TileSys.h"
class Player : public GameObject
{
public:
	Player(TextureLoader& tl);
	~Player(void);
	void move(Vector2f direction);
	void rotate(bool keyPressed);
	void draw(RenderWindow& window);	
	void dodge(bool keyPressed, const Time& dt);
	float getRotation();
	float getX(){return _sprite.getPosition().x;}
	float getSpeed(){return _speed;}
	bool dodgeSwitch;
	bool godMode;
	Vector2f movement;
	Vector2f lastMovement;
	FloatRect _boundaries;
private:
	Sprite _headsprite;
	Clock rotateTick;
	Clock dodgeTick;
	Clock dodgeTime;
};

