#include "Engine.h"
#include <iostream>

#include "Vector.h"
#include "DynamicArray.h"

//class ����
//�ڷᱸ��(STL) ���


int main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	return 0;
}