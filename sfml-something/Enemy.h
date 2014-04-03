#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
public:
	Enemy(TextureLoader& tl, Vector2f position);
	Enemy();
	Enemy(Sprite sprite, Vector2f position, char c);
	virtual ~Enemy(void);
	void rotate(float speed);
	char type;
};

