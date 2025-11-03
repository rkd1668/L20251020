#pragma once

#include "Vector.h"
#include <vector>
//2d
class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();
	
	//virtual fuction table -> vftbl
	//override
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

	template<typename T>
	T* GetComponent()
	{
		for (auto Component : Components)
		{
			if (dynamic_cast<T*>(Component))
			{
				return dynamic_cast<T*>(Component);
			}
		}

		return nullptr;
	}

	virtual void ActorBeginOverlap();
	virtual void Hit();

	void AddComponent(UComponent* InComponent);
	
	std::vector<UComponent*> Components;

protected:
	FVector2D Location;


	

public:
	
};

