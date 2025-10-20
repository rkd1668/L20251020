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

protected:
	std::vector<AActor*> Actors;
};

