#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"
#include <string>
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

	void LoadBMP(std::string FileName);

	int ZOrder = 0;
	SDL_Color Color = { 255, 255, 255, 255 };
	SDL_Surface* BitmapImage = nullptr;
	SDL_Texture* Texture = nullptr;
	SDL_Color ColorKey = { 255, 0, 255, 255 };

	bool bAnimation = false;
	float SpriteCountX = 5;
	float SpriteCountY = 5;
	float XIndex = 0;
	float YIndex = 0;

protected:
	char Shape;
	
};

