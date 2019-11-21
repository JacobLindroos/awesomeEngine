#pragma once
#include <SDL.h>
#include "Key.h"

#include <SDL_image.h>

/*CORE ENGINE METHODS*/

void EngineInitialize();

void EngineUpdate();

void EngineClear();

void EngineClose();

void EngineDestroy();

bool EngineIsOpen();

void EngineRenderSquare(float posX, float posY, int width, int height);

bool EngineGetKey(Key key);

bool EngineGetKeyDown(Key key);

void EngineRenderTexture(float posX, float posY, int height, int width, const char* path);

void EngineRenderBackground(SDL_Rect* src, SDL_FRect* dest, const char* path);