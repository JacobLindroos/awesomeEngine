#pragma once
#include "GameObject.h"
#include "Vector.h"
#include "Engine.h"
#include "Time.h"

class Enemy : public GameObject {
public:
	enum MovementTypes
	{
		Circle, Horizontal, Vertical,
	};

	MovementTypes mt;

	enum ShootTypes
	{
		OneShot, DoubleShot, SpreadShot,
	};

	ShootTypes st;

	Enemy(float posX, float posY, float movementSpeed, MovementTypes mt, ShootTypes st, const char* _path);

	Vector Direction;
	Vector centerPosition = Vector(_posX, _posY);
	float angle = 0.f;
	float radius = 100.f;

	const char* _path;
	float _directionX;
	float _directionY;
	float timer = 0;
	bool enemyShoot = false;

	void Update(float deltaTime) override;
	void Render() override;

	float movementSpeed = 0.f;
	//moving the enemy forward in a circler pattern
	void CircleMove();
	//moving the enemy forward on the x axis
	void HorizontalMove();
	//moving the enemy forward on the y axis
	void VerticalMove();

	void CheckAmmuntion();
};