#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>
#include <map>

using namespace sf;

class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);
	Texture getTex();
	Sprite& getSprite(std::string name);
private:
	IntRect& getRect(std::string name);
	Sprite _sprite;
	Texture *_atlas;
	std::multimap<std::string,IntRect>_rectangles;
};