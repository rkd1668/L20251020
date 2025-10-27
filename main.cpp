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
	while (true);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	return 0;
}