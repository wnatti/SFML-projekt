#include "Enemy.h"
#include <iostream>

Enemy::Enemy(TextureLoader& tl, Vector2f position)
{
	type = 'n';
	_sprite = (tl.getSprite("player"));
	//_sprite.setColor(Color::Red);
	middleOrigin();
	_sprite.setPosition(position);
}

Enemy::Enemy(Sprite sprite, Vector2f position, char c)
{
	type = c;
	_sprite = sprite;
	_sprite.setColor(Color::Red);
	middleOrigin();
	_sprite.setPosition(position);
}

Enemy::Enemy()
{
	type = 'n';
}

void Enemy::rotate(float speed)
{
	_sprite.rotate(speed);
}
Enemy::~Enemy(void)
{
}
