#include "Goal.h"
#include "PaperFlipbookComponent.h"
AGoal::AGoal()
{
	//ZOrder = 1000;
	//Color = { 255, 255, 0, 0 };
	FlipBook = new UPaperFlipbookComponent();
	FlipBook->SetShape('G');
	FlipBook->SetOwner(this);
	FlipBook->ZOrder = 1000;
	FlipBook->Color = SDL_Color{ 255, 255, 0, 0 };
	AddComponent(FlipBook);
}

AGoal::~AGoal()
{
}
