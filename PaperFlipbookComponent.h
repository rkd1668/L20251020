#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"
class UPaperFlipbookComponent : public USceneComponent
{
public:
	UPaperFlipbookComponent();
	~UPaperFlipbookComponent();

	virtual void Tick() override;
	virtual void Render() override;

	__forceinline char GetShape()
	{
		return Shape;
	}

	void SetShape(char Value)
	{
		Shape = Value;
	}

	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}
	int ZOrder;

	SDL_Color Color = { 255, 255, 255, 255 };
protected:
	char Shape;
	
};

