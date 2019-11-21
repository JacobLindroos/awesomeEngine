#pragma once

#include "Enemy.h"

class Enemy01 : public Enemy
{
public:
	Enemy01(float posX, float posY, float movementSpeed, MovementTypes mt, ShootTypes st, const char* path);
};