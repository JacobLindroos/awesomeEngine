#include "Player.h"
#include "Engine.h"
#include "Key.h"
#include "Bullet.h"

Player::Player(float posX, float posY) : GameObject(posX, posY){}

Player::Player(float posX, float posY, const char* path) : GameObject(posX, posY), _path(path){}

void Player::Update(float deltaTime)
{
	_collisionBox.x = _posX;
	_collisionBox.y = _posY;
	_collisionBox.w = 32;
	_collisionBox.h = 64;

	float _directionX = 0.0f;
	float _directionY = 0.0f;

	if (EngineGetKey(Key::W))
	{
		_posY -= 10.f;
		_directionY--;
	}
	if (EngineGetKey(Key::S))
	{
		_posY += 10.f;
		_directionY++;
	}
	if (EngineGetKey(Key::D))
	{
		_posX += 10.f;
		_directionX++;
	}
	if (EngineGetKey(Key::A))
	{
		_posX -= 10.f;
		_directionX--;
	}
	
	if (_directionX == 0 && _directionY == 0)
	{
		_directionX = 1;
	}

	if (EngineGetKeyDown(Key::Space)) {
		_gameWorld->SpawnGameObject(new Bullet(_posX + 5 * _directionX, _posY + 64 * _directionY, _directionX, _directionY));
	}
}

void Player::Render()
{
	EngineRenderTexture(_posX, _posY, 64,64, _path);
}
