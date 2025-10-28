#include "Actor.h"
#include <iostream>
#include <windows.h>
#include "Engine.h"
#include "Component.h"
AActor::AActor() :
	Location(0, 0)
{
}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
}

void AActor::Tick()
{
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

void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}
