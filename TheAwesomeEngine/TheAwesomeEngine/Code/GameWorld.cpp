#include "GameWorld.h"
#include "GameObject.h"

GameWorld::GameWorld()
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		Objects[i] = nullptr;
	}
}

GameWorld::~GameWorld()
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] != nullptr)
		{
			delete Objects[i];
			Objects[i] = nullptr;
		}
	}
}

void GameWorld::Update(float deltaTime)
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == nullptr)
			continue;

		Objects[i]->Update(deltaTime);
	}
}

void GameWorld::Render()
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == nullptr)
			continue;

		Objects[i]->Render();
	}
	
}

void GameWorld::SpawnGameObject(GameObject* go)
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[ i] == nullptr)
		{
			Objects[i] = go;
			break;
		}
	}
	go->_gameWorld = this;
}

void GameWorld::DestroyGameObjetc(GameObject* go)
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == go) {
			Objects[i] = nullptr;
			delete go;
			break;
		}
	}
}
