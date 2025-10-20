#pragma once

#include "Vector.h"
//2d

class AActor
{
public:
	AActor();
	virtual ~AActor();
	
	//virtual fuction table -> vftbl
	virtual void Tick(); //이건 자식이 재정의 할 수도 있다.

	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		//Location = Value;
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

private:
	FVector2D Location;
};

