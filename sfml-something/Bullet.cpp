#include "Bullet.h"
#include "Player.h"

static const float PII = 3.14159265;

Bullet::Bullet(Vector2f pos, float rotation, TextureLoader tl, float velocity)
{
	_sprite = (tl.getSprite("bullet"));
	_sprite.setPosition(pos);
	_sprite.scale(1.5f,1.0f);
	_rotation = rotation;
	//_boundaries = _sprite.getGlobalBounds();
	_sprite.setRotation(_rotation+90);
	_velocity = velocity;
}

void Bullet::move(const Time& dt)
{
	_velocity*=1.01f;
	float delta = dt.asSeconds()*75*_velocity;

	_sprite.move((cos(_sprite.getRotation()*PII/180)*delta),(sin(_sprite.getRotation()*PII/180))*delta);
}

void Bullet::hitWarn()
{
	_sprite.setColor(Color::Red);
}

Bullet::~Bullet(void)
{
	//std::cout << "wut \n";
}
