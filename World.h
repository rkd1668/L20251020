#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	std::vector<AActor*> GetAllActors() const;
	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();
	virtual void Render();

	static bool CompareActorZOrder(AActor* a,AActor* b);

	void SortActor();

	void SortActorsByZOrder();

	void SelectionSortActors();
protected:
	std::vector<AActor*> Actors;
};

