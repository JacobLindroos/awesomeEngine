#pragma once
#include "GameWorld.h"
#include <SDL.h>
class GameObject
{
public:
	GameObject(float posX, float posY);
	
	virtual void Update(float deltaTime) = 0;
	virtual void Render();

	int _posX, _posY;
	
	SDL_Rect _collisionBox;

	GameWorld* _gameWorld;
};
