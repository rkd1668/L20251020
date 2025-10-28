#include "Floor.h"
#include "PaperFlipbookComponent.h"
AFloor::AFloor()
{
	//ZOrder = 0;
	//Color = { 0, 0, 0, 0 };

	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape(' ');
	Paper->SetOwner(this);
	Paper->ZOrder = 0;
	Paper->Color = SDL_Color{ 0, 0, 0, 0 };
	AddComponent(Paper);
}

AFloor::~AFloor()
{
}
