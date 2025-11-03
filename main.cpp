#include "Engine.h"
#include <SDL3/SDL_main.h>

int SDL_main(int argc, char* argv[])
{
	SDL_Time deltaSeconds = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	deltaSeconds = SDL_GetTicks64() - deltaSeconds;

	return 0;
}