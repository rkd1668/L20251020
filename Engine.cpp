#include "Engine.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>

#include "Wall.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Floor.h"
#include "GameMode.h"


#pragma comment(lib, "SDL3")

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() :
	World(nullptr)
{
}

FEngine::~FEngine()
{
}
 
void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
}

void FEngine::OpenLevel()
{
	srand((unsigned int)time(nullptr));
	World = new UWorld;

	std::ifstream MapFile("Level01.map");

	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); X++)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}

	MapFile.close();

	World->SortActor();

	World->SpawnActor(new AGameMode());
	//World->SelectionSortActors();
	//World->SortActorsByZOrder();
	//std::sort(World->GetAllActors().begin(), World->GetAllActors().end(), World->CompareActorZOrder);
	//MapFile.close();
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);
		//Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
}

void FEngine::Input()
{
	if (_kbhit())
	{
		KeyCode = _getch();
	}
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	//system("cls");
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}
