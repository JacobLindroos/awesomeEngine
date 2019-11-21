#include "Bullet.h"
#include "Engine.h"
#include "Type.h"
#include "Enemy.h"
#include "Player.h"
#include "Enemy01.h"
#include <iostream>

void Bullet::Update(float deltaTime)
{
	_posX += 20.f * _dirX;
	_posY += 20.f * _dirY;

	_collisionBox.x = _posX;
	_collisionBox.y = _posY;
	_collisionBox.w = 20;
	_collisionBox.h = 20;

	lifetime -= 0.1f;
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		GameObject* goPtr = _gameWorld->Objects[i];
		if (goPtr == nullptr || goPtr == this)
		{
			continue;
		}

		if (IsA<Enemy01>(goPtr)) {
			if (CheckCollision(_collisionBox, goPtr->_collisionBox)) {
				_gameWorld->DestroyGameObjetc(goPtr);
				_gameWorld->DestroyGameObjetc(this);
				return;
			}
		}

		if (IsA<Player>(goPtr))
		{
			if (CheckCollision(_collisionBox, goPtr->_collisionBox))
			{
				_gameWorld->DestroyGameObjetc(goPtr);
				_gameWorld->DestroyGameObjetc(this);
				return;
			}
		}
	}

	if (lifetime <= 0)
	{
		_gameWorld->DestroyGameObjetc(this);
		return;
	}
}

void Bullet::Render()
{
	EngineRenderSquare(_posX, _posY, 20,20);
}

bool Bullet::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	/*calculate a*/
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	/*B*/
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA  <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}
