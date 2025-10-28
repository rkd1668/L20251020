#include "Engine.h"
#include "Player.h"
#include "World.h"
#include <iostream>

APlayer::APlayer()
{
	ZOrder = 1003;
	bIsCollision = true;
	bIsOverlap = true;
	Color = { 255, 0, 0, 0 };
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation;
	SaveLocation = Location;
	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		Location.X--;
	}
	if (KeyCode == 'd')
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
