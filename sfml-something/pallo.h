#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace std;

class pallo
{
public:
	pallo();
	sf::CircleShape getpallo(void);
	~pallo(void);
	
private:

	sf::CircleShape shape;
	sf::Vector2<float>position;
	float r;
	float x;
	float y;

};

