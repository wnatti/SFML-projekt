#include "Game.h"
#include "GameObject.h"
static void update(RenderWindow& window, Game& game);
Clock deltaClock;

int main()
{	
	TextureLoader texLoad;
    RenderWindow window(VideoMode(800,640), "GudGame (tm)");
	window.setFramerateLimit(60);
	Game game(window, texLoad);
	update(window,game);

	return 0;
}

void update(RenderWindow& window, Game& game)
{
	while (window.isOpen())
		{

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						window.close();

			game.update(deltaClock.getElapsedTime());
			deltaClock.restart();
			game.draw();
		}
}