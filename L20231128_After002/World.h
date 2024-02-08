#pragma once
#include "SDL.h"

class UWorld
{
	UWorld();
	~UWorld();

	static SDL_Window* MyWindow = SDL_CreateWindow("MyGame", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

};

 