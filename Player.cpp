#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	std::cout << "Player 持失切" << std::endl;
}

APlayer::~APlayer()
{
	std::cout << "Player 社瑚切" << std::endl;
}

void APlayer::Tick()
{
	AActor::Tick();

	std::cout << "Player Tick" << std::endl;
}
