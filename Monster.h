#pragma once
#include "Actor.h"

class UCollisionComponent;
class UPaperFlipbookComponent;

class AMonster :  public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;

	float ExecuteTime = 0.5f;
	float TotalTime = 0.f;

	UCollisionComponent* Collision;
	UPaperFlipbookComponent* Flipbook;
};

