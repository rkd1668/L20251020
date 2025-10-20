#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick() override; //이건 부모한테 있는건데 재정의 함, 내 자식도 재정의 가능
};

