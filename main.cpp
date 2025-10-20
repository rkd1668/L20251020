#include <iostream>
#include "Actor.h"
#include "Player.h"

using namespace std;

//entry point
int main()
{
	AActor* MyPlayer = new APlayer();

	MyPlayer->Tick();

	delete MyPlayer;
	return 0;
}