#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#pragma comment(lib, "SDL3")

//c++ console entry -> iOS, Window, Linux
//int main(int argc, char* argv[])
//{
//
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	SDL_Event MyEvent;
	
	bool bIsRunning = true;
	while (bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			if (MyEvent.type == SDL_EVENT_QUIT)
			{
				bIsRunning = false;
			}
			//윈도우처리
		}
		else
		{
			//command queue
			SDL_SetRenderDrawColor(MyRenderer, 0, 0, 255, 0);
			SDL_RenderClear(MyRenderer);
			//화면 업데이트
			
			for (int i = 0; i < 100; i++)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(255), SDL_rand(255), SDL_rand(255), 0);
				SDL_FRect Rect = { SDL_rand(640), SDL_rand(480), SDL_rand(200) + 1, SDL_rand(200) + 1 };
				SDL_RenderFillRect(MyRenderer, &Rect);
				SDL_RenderRects(MyRenderer, &Rect, 1);
			}
			SDL_RenderPresent(MyRenderer);
		}
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
	return 0;
}