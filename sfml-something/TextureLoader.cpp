#include "TextureLoader.h"

TextureLoader::TextureLoader(void)
{
	//Pelissä luodaan vain yksi TextureLoader,
	//joten kuva ladataan tekstuurin vain kerran pelissä tässä kohtaa,
	//jokainen assetti käyttää tätä samaa tekstuuria pelissä, mutta eri kohtia siitä

	std::cout << "TextureLoader created" << std::endl;
	Texture* t = new Texture;
	t->loadFromFile("Textures.png");
	_atlas = t;
	IntRect torso(38,0,10,17);
	IntRect head(1,1,31,31);
	IntRect bullet(33,0,4,4);
	IntRect box(49,0,19,18);
	IntRect player(0,0,32,32);
	_rectangles.insert((std::make_pair("head",head)));
	_rectangles.insert((std::make_pair("bullet",bullet)));
	_rectangles.insert((std::make_pair("torso",torso)));
	_rectangles.insert((std::make_pair("box",box)));
	_rectangles.insert((std::make_pair("player",player)));
}

//hakee syötetyllä nimellä(string) int rectanglen, joka antaa tekstuurin kordinaatit atlaksesta
IntRect& TextureLoader::getRect(std::string name)
{
	std::multimap<std::string,IntRect>::iterator it;
	it = _rectangles.find(name);
	return (*it).second;
	//**tee checkki tähän löytyykö nimellä mitään**
}


//Funktio jolla haetaan, oikea IntRect(*katso getRect())
//syöttämällä parametriksi haettava tekstuurin pätkä
Sprite& TextureLoader::getSprite(std::string name)
{
	_sprite.setTexture(*_atlas);
	_sprite.setTextureRect(getRect(name));
	return _sprite;
}


TextureLoader::~TextureLoader(void)
{

}
