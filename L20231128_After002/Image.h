#pragma once

#include <iostream>
#include "SDL.h"

class Image
{
public:

	Image();
	~Image();
protected:
	SDL_Renderer* Character = SDL_CreateRenderer(MyWindow, 0, SDL_RENDERER_ACCELERATED);


private:

};

