#include "Engine.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>

#include "Wall.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Floor.h"

FEngine* GEngine = nullptr;

FEngine::FEngine() :
	World(nullptr)
{
}

FEngine::~FEngine()
{
}
 
void FEngine::Init()
{
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
				else if (Line[X] == ' ')
				{
					AActor* NewActor = new AFloor();
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
			}
			Y++;
		}
	}

	MapFile.close();

}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{

}

void FEngine::Input()
{
	int KeyCode = _getch();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	//system("cls");
	GetWorld()->Render();
}
