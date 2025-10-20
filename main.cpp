#include "Engine.h"

using namespace std;

//entry point
int main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();
	
	delete GEngine;

	return 0;
}