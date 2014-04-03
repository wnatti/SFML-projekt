#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(RenderWindow& window, TextureLoader& tl)
	:_window(window),_textureLoader(tl),_player(tl),_tileSys(tl)
	,_bulletSys(),_enemySys(0,tl)
{
	_enemySys.spawnEnemy(Vector2f(100,200));
	_enemySys.spawnEnemy(Vector2f(200,10));
	_enemySys.spawnEnemy(Vector2f(200,50));
	_enemySys.spawnEnemy(Vector2f(200,100));
	//_enemySys.spawnEnemy(Vector2f(200,150));
	//_enemySys.spawnEnemy(Vector2f(200,250));
	//_enemySys.spawnEnemy(Vector2f(200,350));
	_enemySys.spawnEnemyShotgun(Vector2f(200,450));
	_enemySys.spawnEnemyShotgun(Vector2f(200,550));
}


Game::~Game(void)
{
}

void Game::update(const Time& dt)
{
	_player.move(Input::movePlayer(dt,_player,_tileSys));
	_player.dodge(Input::dodgeJump(),dt);
	_player.rotate(Input::rotatePlayer());
	_bulletSys.init(_tileSys.getTVector());
	_bulletSys.shootBullet(_window, dt ,_textureLoader, _enemySys);
	_enemySys.rotateLikeAMadCunt(dt);
	_bulletSys.checkStillCollision();
	_bulletSys.checkPlayerCollision(_player);
	//_tileSys.checkCollision();
	//_tileSys.eraseCollided(_bulletSys);
	//cout << _player.getRotation() << endl;
	//cout << _player.getPosition().x << " " << _player.getPosition().y << endl;

}
void Game::draw()
{
	_window.clear(sf::Color::Black);
	_bulletSys.drawBullet(_window);
	_tileSys.draw(_window);
	_player.draw(_window);
	_enemySys.draw(_window);
	
	_window.display();
}