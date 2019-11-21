#pragma once
#include "GameObject.h"

class Bullet :public GameObject {
public:
	Bullet(float posX, float posY, float dirX, float dirY): GameObject(posX, posY), _dirX(dirX), _dirY(dirY){}

	void Update(float deltaTime) override;
	void Render()override;

	bool CheckCollision(SDL_Rect a, SDL_Rect b);


private:
	float _dirX;
	float _dirY;
	float lifetime = 2.f;
};