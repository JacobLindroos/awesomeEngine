#pragma once

#include "Time.h"

#define MAX_GAME_OBJECTS 250

class GameObject;

class GameWorld
{
public:
	GameWorld();
	~GameWorld();
	
	GameObject* Objects[MAX_GAME_OBJECTS];

	void Update(float deltaTime);
	void Render();

	void SpawnGameObject(GameObject * go);
	void DestroyGameObjetc(GameObject* go);
};

