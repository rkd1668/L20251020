#include "Engine.h"
#include <iostream>

#include "Vector.h"
#include "DynamicArray.h"

//class ����
//�ڷᱸ��(STL) ���


int main(int argc, char* argv[])
{
	TDynamicArray<int> D;
	D.PushBack(1);
	D.PushBack(2);
	D.PushBack(3);
	
	//���� ������, ���� ����
	TDynamicArray<int> D2 = D;

	D2[2] = 4;
	std::cout << D[2] << std::endl;
	/*FVector2D A(1, 1);
	FVector2D B;
	B = A;*/
	return 0;
}