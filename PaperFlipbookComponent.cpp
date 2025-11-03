#include "PaperFlipbookComponent.h"
#include "Vector.h"
#include <Windows.h>
#include "Actor.h"
#include <iostream>
#include "Engine.h"

UPaperFlipbookComponent::UPaperFlipbookComponent()
{
}

UPaperFlipbookComponent::~UPaperFlipbookComponent()
{
	if (BitmapImage)
	{
		SDL_DestroySurface(BitmapImage);
		BitmapImage = nullptr;
	}

	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
}

void UPaperFlipbookComponent::Tick()
{
	if (bAnimation)
	{
		XIndex++;
		XIndex = (float)((int)XIndex % (int)SpriteCountX);
	}
}

void UPaperFlipbookComponent::Render()
{
	//COORD Position;
	//Position.X = GetOwner()->GetActorLocation().X;
	//Position.Y = GetOwner()->GetActorLocation().Y;

	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	//std::cout << Shape;
	int SizeX = 30;
	int SizeY = 30;

	if (!BitmapImage && !Texture)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
		
		//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
		SDL_FRect DrawRect =
		{
			(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY
		};
		SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
	}
	else
	{
		SDL_FRect SourceRect;
		if (bAnimation)
		{
			float SpriteSizeX = (float)BitmapImage->w / SpriteCountX;
			float SpriteSizeY = (float)BitmapImage->h / SpriteCountY;
			SourceRect = { XIndex * SpriteSizeX, YIndex * SpriteSizeY, SpriteSizeX, SpriteSizeY };
		}
		else
		{
			SourceRect = { 0, 0, (float)BitmapImage->w, (float)BitmapImage->h };
		}
		
		SDL_FRect DestinationRect = {
			(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY
		};
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &DestinationRect);
	}

}

void UPaperFlipbookComponent::LoadBMP(std::string FileName)
{
	BitmapImage = SDL_LoadBMP(FileName.c_str());
	
	SDL_SetColorKey(BitmapImage, true, SDL_MapRGBA(SDL_GetPixelFormatDetails(BitmapImage->format), nullptr, ColorKey.r, ColorKey.g, ColorKey.b, ColorKey.a));
	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, BitmapImage);
}
