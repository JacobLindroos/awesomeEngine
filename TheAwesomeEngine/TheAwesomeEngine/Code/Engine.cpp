#include "Engine.h"
#include "Time.h"
#include <chrono>
#include <SDL.h>
#include <iostream>


struct InputState {
	bool keyIsPressed;
	int _frameNumber;
};

static SDL_Window* _window;
static SDL_Renderer* _renderer;
static SDL_Color _currentColor = { 255,255,255,255 };

static bool bIsOpen = true;

static InputState  keyStates[(unsigned int)Key::MAX];

static float _currentFrameNumber = 1;

void EngineInitialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("The Awesomest Engine Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false);
	if (!_window)
	{
		std::cout << "SDL_Window error: " << SDL_GetError() << "\n";
		EngineClose();
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (!_renderer)
	{
		std::cout << "SDL_Renderer error: " << SDL_GetError() << "\n";
		EngineClose();
	}

	bIsOpen = true;
}


void EngineUpdate()
{
	_currentFrameNumber++;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			EngineClose();
		}

		if (event.type == SDL_KEYDOWN) {
			if (event.key.repeat == 0)
			{
				InputState& state = keyStates[event.key.keysym.scancode];
				state.keyIsPressed = true;
				state._frameNumber = _currentFrameNumber;
			}
		}
		if (event.type == SDL_KEYUP)
		{
			InputState& state = keyStates[event.key.keysym.scancode];
			state.keyIsPressed = false;
			state._frameNumber = _currentFrameNumber;
		}
	}

	SDL_RenderPresent(_renderer);
	EngineClear();
}


void EngineClear()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
}


void EngineClose()
{
	bIsOpen = false;
}


void EngineDestroy()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	IMG_Quit();
	SDL_Quit();
}


bool EngineIsOpen()
{
	return bIsOpen;
}


void EngineRenderSquare(float posX, float posY, int width, int height)
{
	SDL_SetRenderDrawColor(_renderer, _currentColor.r, _currentColor.g, _currentColor.b, _currentColor.a);
	SDL_FRect Square = { posX, posY, width, height };
	SDL_RenderFillRectF(_renderer, &Square);
}


bool EngineGetKey(Key key)
{
	return keyStates[(int)key].keyIsPressed;
}


bool EngineGetKeyDown(Key key)
{
	InputState& state = keyStates[(int)key];
	return state.keyIsPressed && state._frameNumber == _currentFrameNumber;
}


void EngineRenderTexture(float posX, float posY, int height, int width, const char* path)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);

	if (tempSurface == nullptr)
	{
		puts("failed to find path!");
	}

	SDL_Rect dest = { posX, posY, width, height };
	SDL_Rect src = { 0,0, tempSurface->w, tempSurface->h };

	SDL_RenderCopy(_renderer, texture, &src, &dest);

	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(texture);
}

void EngineRenderBackground(SDL_Rect* src, SDL_FRect* dest, const char* path)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);

	if (tempSurface == nullptr)
	{
		puts("failed to find path!");
	}

	SDL_RenderCopyF(_renderer, texture, src, dest);

	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(texture);
}
