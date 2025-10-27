#include "Monster.h"
#include "World.h"
#include "Engine.h"
#include <iostream>
AMonster::AMonster()
{
	ZOrder = 1001;
	bIsCollision = true;
	bIsOverlap = true;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	int KeyCode = rand() % 4;
	FVector2D SaveLocation;
	SaveLocation = Location;
	if (KeyCode == 0)
	{
		Location.Y--;
	}
	if (KeyCode == 1)
	{
		Location.Y++;
	}
	if (KeyCode == 2)
	{
		Location.X--;
	}
	if (KeyCode == 3)
	{
		Location.X++;
	}
	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		if (CheckCollision(OtherActor))
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}
