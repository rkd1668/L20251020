#include "Engine.h"
#include "Player.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFlipbookComponent.h"
#include "CollisionComponent.h"
#include <iostream>


APlayer::APlayer()
{
	//ZOrder = 1003;
	//bIsCollision = true;
	//bIsOverlap = true;
	//Color = { 255, 0, 0, 0 };

	Flipbook = new UPaperFlipbookComponent();
	Flipbook->SetShape('P');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 1003;
	Flipbook->Color = SDL_Color{ 255, 0, 0, 255 };
	AddComponent(Flipbook);

	Collision = new UCollisionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	AddComponent(Collision);
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation;
	SaveLocation = Location;
	if (KeyCode == SDLK_w || KeyCode == SDLK_UP)
	{
		Location.Y--;
		Flipbook->YIndex = 2;
	}
	if (KeyCode == SDLK_s || KeyCode == SDLK_DOWN)
	{
		Location.Y++;
		Flipbook->YIndex = 3;
	}
	if (KeyCode == SDLK_a || KeyCode == SDLK_LEFT)
	{
		Location.X--;
		Flipbook->YIndex = 0;
	}
	if (KeyCode == SDLK_d || KeyCode == SDLK_RIGHT)
	{
		Location.X++;
		Flipbook->YIndex = 1;
	}

	if (KeyCode == SDLK_ESCAPE)
	{
		exit(-1);
	}

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);
	
	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		for (auto Component : OtherActor->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(Component);
			if (OtherCollision)
			{
				if (Collision->CheckCollision(OtherCollision))
				{
					bFlag = true;
					break;
				}
			}
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
	
}
