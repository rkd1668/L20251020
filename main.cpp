#include "Engine.h"
#include <iostream>

#include "Vector.h"
#include "DynamicArray.h"

//class 설계
//자료구조(STL) 사용


int main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	return 0;
}