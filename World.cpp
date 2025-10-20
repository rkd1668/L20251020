#include "World.h"
#include "Actor.h"
#include <algorithm>

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

std::vector<AActor*> UWorld::GetAllActors() const
{
	return Actors;
}

//���丮 ����(������ ���Լ��� ��)
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

