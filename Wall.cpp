#include "Wall.h"
#include "PaperFlipbookComponent.h"

AWall::AWall()
{
	//ZOrder = 1000;
	bIsCollision = true;
	bIsOverlap = false;
	//Color = { 128, 128, 128, 0 };
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	AddComponent(Paper);
}

AWall::~AWall()
{
}
