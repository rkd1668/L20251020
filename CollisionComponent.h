#pragma once
#include "SceneComponent.h"
class UCollisionComponent : public USceneComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void Tick() override;

	bool CheckCollision(const UCollisionComponent* Other);

	bool bIsCollision = false;
	bool bIsOverlap = true;
};

