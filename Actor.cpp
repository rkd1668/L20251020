#include "Actor.h"
#include <iostream>
#include <windows.h>
#include "Engine.h"

AActor::AActor() :
	Shape(' '), Location(0, 0)
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Position;
	Position.X = Location.X;
	Position.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;
	
	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	int SizeX = 30;
	int SizeY = 30;

	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
	SDL_FRect DrawRect = { Location.X * SizeX, Location.Y * SizeY, SizeX, SizeY };
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}

bool AActor::CheckCollision(const AActor* OtherActor)
{
	if (OtherActor->bIsOverlap) {
		return false;
	}
	if (OtherActor->bIsCollision && bIsCollision && this->Location == OtherActor->Location && this != OtherActor) 
	{
		return true;
	}

	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}
