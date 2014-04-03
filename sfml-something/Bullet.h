#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
public:
	Bullet(Vector2f pos, float rotation, TextureLoader tl, float velocity);
	~Bullet(void);
	void move(const Time &dt);
	FloatRect getGlobalBounds(){return _sprite.getGlobalBounds();}
	void hitWarn();
private:
	float _rotation;
	float _velocity;
};