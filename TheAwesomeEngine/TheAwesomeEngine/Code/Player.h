#pragma once
#include "GameObject.h"


class Player :public GameObject {
public:
	Player(float posX, float posY);
	Player(float posX, float posY, const char* path);

	const char* _path;

	void Update(float deltaTime) override;
	void Render() override;

};