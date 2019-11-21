#include <SDL.h>
#include "Code/Engine.h"
#include "Code/GameObject.h"
#include "Code/Player.h"
#include "Code/Enemy.h"
#include "Code/Enemy01.h"
#include "Code/Background.h"
#include "Code/Time.h"
#include <iostream>

const float targetFramerate = 80;
const float frameDelay = 1000 / targetFramerate;
float frametime = 0;

Time time;

bool isOpen = false;

int main(int argc, char* argv[]) {

	EngineInitialize();

	SDL_Event keyEvent;
	while (EngineIsOpen()) {

		GameWorld Game;
		Game.SpawnGameObject(new Background(560.f, 0.f, 800, 3200, "Res/skyCloudsSeemless_v003.png" ));
		Game.SpawnGameObject(new Player(928, 950.f, "Res/Ma_Man.png"));
		Game.SpawnGameObject(new Enemy(928, -100, 10, Enemy::Vertical, Enemy::DoubleShot, "Res/Ma_Man_Enemy.png"));

		while (EngineIsOpen())
		{
			time.StartFrame();
			EngineClear();

			Game.Update(time.DeltaTime());
			Game.Render();

			EngineUpdate();
			time.EndFrame();

			// Wait to achieve target framerate 
			if (time.DeltaTime() < frameDelay)
			{
				SDL_Delay(frameDelay - time.DeltaTime());
			}
		}
	}
	EngineDestroy();

	return 0;
}
