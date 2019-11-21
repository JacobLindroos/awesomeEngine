#include "GameObject.h"
#include "Engine.h"

GameObject::GameObject(float posX, float posY):_posX(posX), _posY(posY)
{}


void GameObject::Render()
{
	EngineRenderSquare(_posX, _posY, 64, 64);
}
