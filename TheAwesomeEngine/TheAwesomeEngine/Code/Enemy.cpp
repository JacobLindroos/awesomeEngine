#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"

Enemy::Enemy(float posX, float posY, float movementSpeed, MovementTypes mt, ShootTypes st, const char* path) : GameObject(posX, posY), movementSpeed(movementSpeed), mt(mt), st(st), _path(path)
{
	_collisionBox.x = posX;
	_collisionBox.y = posY;
	_collisionBox.w = 32;
	_collisionBox.h = 32;

	_directionX = 1.0f;
	_directionY = 1.0f;
}

void Enemy::Update(float deltaTime)
{
	_collisionBox.x = _posX;
	_collisionBox.y = _posY;
	_collisionBox.w = 32;
	_collisionBox.h = 32;

	if (mt == Circle)
	{
		CircleMove();
		if (centerPosition.y > 25.f && centerPosition.y < 800.f)
		{
			CheckAmmuntion();
		}
	}
	if (mt == Horizontal)
	{
		HorizontalMove();
		if (_posX > 50.f && _posX < 550.0f)
		{
			CheckAmmuntion();
		}
	}
	if (mt == Vertical)
	{
		VerticalMove();
		if (_posY > 25.f && _posY < 950.f)
		{
			CheckAmmuntion();
		}
	}
	timer += deltaTime;
}


//Renders the enemy sprite 
void Enemy::Render()
{
	if (_path)
	{
		EngineRenderTexture(_posX, _posY, 64, 64, _path);
	}
	else
	{
		EngineRenderSquare(_posX, _posY, 32, 32);
	}
}


void Enemy::CircleMove()
{
	angle += 0.1f;

	float x = centerPosition.x + cos(angle) * radius;
	float y = centerPosition.y + sin(angle) * radius;

	_posX = x;
	_posY = y;

	centerPosition.y += .8f;

	if (centerPosition.y > 1100.f)
	{
		centerPosition.y = -100.f;
	}
}


void Enemy::HorizontalMove()
{
	_posX += 3.f;

	if (_posX > 650.f)
	{
		_posX = -100.f;
	}
}


void Enemy::VerticalMove()
{
	_posY += 3.f;

	if (_posY > 1100.f)
	{
		_posY = -100.f;
	}
}


void Enemy::CheckAmmuntion()
{
	if (timer > 1)
	{
		if (st == OneShot)
		{
			_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 64 * _directionY, 0, _directionY));
		}
		if (st == DoubleShot)
		{
			_gameWorld->SpawnGameObject(new Bullet(_posX + 46, _posY + 64 * _directionY, 0, _directionY));
			_gameWorld->SpawnGameObject(new Bullet(_posX -14, _posY + 64 * _directionY, 0, _directionY));
		}
		if (st == SpreadShot)
		{
			_gameWorld->SpawnGameObject(new Bullet(_posX + 26, _posY + 64 * _directionY, -1, _directionY));
			_gameWorld->SpawnGameObject(new Bullet(_posX + 16, _posY + 64 * _directionY, 0, _directionY));
			_gameWorld->SpawnGameObject(new Bullet(_posX - 6, _posY + 64 * _directionY, 1, _directionY));
		}
		timer = 0;
	}
}
