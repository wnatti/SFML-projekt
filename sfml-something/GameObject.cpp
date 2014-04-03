#include "GameObject.h"


GameObject::GameObject()
{
	
}

void GameObject::middleOrigin()
{
	_sprite.setOrigin(_sprite.getTextureRect().width*0.5,_sprite.getTextureRect().height*0.5);
}
void GameObject::draw(RenderWindow& window)
{
	window.draw(_sprite);
}


GameObject::~GameObject(void)
{
}
