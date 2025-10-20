#include "Engine.h"
#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	ZOrder = 1003;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		Location.X--;
	}
	if (KeyCode == 'd')
	{
		Location.X++;
	}
}
