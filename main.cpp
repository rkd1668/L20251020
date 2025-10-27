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
			SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
			SDL_RenderClear(MyRenderer);
			//화면 업데이트
			
			//중심 0, 0, 반지름 1
			for (int j = 0; j < 1; ++j)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(255), SDL_rand(255), SDL_rand(255), 0);

				//중심 0, 0, 반지름 1
				int Radius = SDL_rand(630) + 10;
				int CenterX = SDL_rand(640);
				int CenterY = SDL_rand(480);
				//int Radius = 300;
				//int CenterX = 320;
				//int CenterY = 240;
				for (int Degree = 30; Degree <= 360; Degree += 30)
				{
					int OldX = SDL_cos((float)(Degree - 30) * SDL_PI_F / 180.0f) * Radius + CenterX;
					int OldY = SDL_sin((float)(Degree - 30) * SDL_PI_F / 180.0f) * Radius + CenterY;

					int X = SDL_cos((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterX;
					int Y = SDL_sin((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterY;

					SDL_RenderLine(MyRenderer, OldX, OldY, X, Y);
				}
			}


			SDL_RenderPresent(MyRenderer);
		}
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
	return 0;
}