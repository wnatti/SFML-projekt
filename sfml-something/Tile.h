#pragma once
#include "SFML\Graphics.hpp"
#include "TextureLoader.h"
#include "GameObject.h"

class Tile
	:public GameObject
{
public:
	Tile(TextureLoader &tl, Vector2f position);
	FloatRect getBounds(){return _sprite.getGlobalBounds();}
	~Tile(void);
private:
};

