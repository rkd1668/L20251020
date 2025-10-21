#include "World.h"
#include "Actor.h"
#include <algorithm>

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors) const
{
	OutActors = Actors;
}

//팩토리 패턴(생성도 이함수가 함)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	//All Actors Process.
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}

}

bool UWorld::CompareActorZOrder(AActor* a,AActor* b)
{
	return a->GetZOrder() < b->GetZOrder();
}

void UWorld::SortActor()
{
	for (int j = 0; j < Actors.size(); j++)
	{
		for (int i = 0; i < Actors.size(); i++)
		{
			if (Actors[j]->GetZOrder() < Actors[i]->GetZOrder())
			{
				AActor* Temp = Actors[j];
				Actors[j] = Actors[i];
				Actors[i] = Temp;
			}
		}
	}
}

void UWorld::SortActorsByZOrder()
{
	std::sort(Actors.begin(), Actors.end(), CompareActorZOrder);
}

void UWorld::SelectionSortActors()
{
	int Min = 3000;
	AActor* Tmp;
	int Index = 0;
	for (int i = 0; i < Actors.size() - 1; i++)
	{
		for (int j = i; j < Actors.size(); j++)
		{
			if (Min > Actors[j]->GetZOrder())
			{
				Min = Actors[j]->GetZOrder();
				Index = j;
			}
		}
		Tmp = Actors[i];
		Actors[i] = Actors[Index];
		Actors[Index] = Tmp;
	}
}

