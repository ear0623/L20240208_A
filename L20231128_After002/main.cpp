#include <iostream>
#include "SDL.h"
#include "Image.h"

#pragma comment(lib,"SDL2")//전처리로 기능을 쓰겠다. 선언
#pragma comment(lib, "SDL2main")//

int SDL_main(int argc,char* arcv[])//cout<<arg<<endl;->인자갯수 cout<<argv[]<<endl;->인자겟수
//argument count, argument valuable
{
	srand((unsigned int)time(nullptr));

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("MyGame", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event MyEvent;

	int R = 0;
	int G = 0;
	int B = 0;
	int A = 0;
	bool isRunning = true;
	//image
	SDL_Surface* CharacterImage = SDL_LoadBMP("test.bmp");
	if (!CharacterImage)
	{
		SDL_DestroyRenderer(MyRenderer);
		SDL_DestroyWindow(MyWindow);
		std::cout << !CharacterImage;

		return 0;
	}
	SDL_Texture* CharacterTexture = SDL_CreateTextureFromSurface(MyRenderer, CharacterImage);
	SDL_FreeSurface(CharacterImage);
	if (!CharacterTexture)
	{
		SDL_DestroyRenderer(MyRenderer);
		SDL_DestroyWindow(MyWindow);
		std::cout << !CharacterImage;
	}
	//
	//
	SDL_SetRenderDrawColor(MyRenderer, R, G, B, A);
	SDL_RenderClear(MyRenderer);

	while (isRunning)
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
			if (MyEvent.key.keysym.sym == SDLK_UP)
			{
				std::cout << "Up";
			}
			if (MyEvent.key.keysym.sym == SDLK_DOWN)
			{
				std::cout << "Down";
			}
			if (MyEvent.key.keysym.sym == SDLK_LEFT)
			{
				std::cout << "Left";
			}
			if (MyEvent.key.keysym.sym == SDLK_RIGHT)
			{
				std::cout << "Right";
			}
			break;
		}
		//todo
		
		
		
		
	
		
	}
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	return 0;
}