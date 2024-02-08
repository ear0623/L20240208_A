#include <iostream>

#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

int SDL_main(int argc, char* argv[])
{
	srand((unsigned int)time(nullptr));

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow= SDL_CreateWindow("Hellow World", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	Uint64 DeltaSeconds = SDL_GetTicks64();
	Uint64 LastTime = SDL_GetTicks64();
	SDL_Event MyEvent;
	bool IsRunning = true;
	while (IsRunning)//message loop oneframe drawcall 윈도우 큐
	{
		DeltaSeconds = SDL_GetTicks64() - LastTime;
		LastTime = SDL_GetTicks64();
		std::cout << DeltaSeconds << std::endl;

		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			IsRunning = false;
			break;

		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
			break;

		}
		//명령어 죄다 저장
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0x00);//0x"ff"->16진수 RGB코드값
		SDL_RenderClear(MyRenderer);
		//actor->Render();
		for (int i = 0; i < 10; i++)
		{
			int x = rand() % 600;
			int y = rand() % 400;
			int w = rand() % 90+10;
			int h = rand() % 90+10;
			int R = rand() % 256;
			int G = rand() % 256;
			int B = rand() % 256;
			int A = rand() % 256;
			SDL_SetRenderDrawColor(MyRenderer, R, G, B, A);
			SDL_Rect MyRect = { x,y,w,h };
			SDL_RenderFillRect(MyRenderer, &MyRect);
		}

		
		SDL_RenderPresent(MyRenderer);

	}

	SDL_Quit();
	return 0;
}