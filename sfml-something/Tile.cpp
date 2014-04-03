#include "Tile.h"


Tile::Tile(TextureLoader &tl, Vector2f position)
{
	_sprite = (tl.getSprite("box"));
	_sprite.setPosition(position);
}


Tile::~Tile(void)
{
}
