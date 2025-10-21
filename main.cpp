#include "Engine.h"
#include <iostream>
using namespace std;



void A()
{
	std::cout << "A" << std::endl;
}

void B()
{
	std::cout << "B" << std::endl;
}

int Sum(int A, int B)
{
	return A + B;
}

int Minus(int A, int B)
{
	return A - B;
}

void Sort(bool (*Compare)(int A, int B))
{
	int Numbers[10] = { 10, 6, 4, 3, 5, 7, 9, 1, 2, 8 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Compare(Numbers[i], Numbers[j]))
			{
				int Temp = Numbers[i];
				Numbers[i] = Numbers[j];
				Numbers[j] = Temp;
			}
			
		}
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << Numbers[i] << std::endl;
	}
}

bool Greater(int A, int B)
{
	return A > B;
}

bool Less(int A, int B)
{
	return A < B;
}

//Callback
void OnReceive(int (*Callback)())
{
	bool bEnd = false;
	while (!bEnd)
	{

	}
	Callback();
}

//void Print(int* Numbers, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << Numbers[i] << endl;
//	}
//
//}
//void Print(float* Numbers, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << Numbers[i] << endl;
//	}
//
//}
//
//void Print(void* Numbers, int _SizeOfElement, int _NumberOfElement)
//{
//	for (int i = 0; i < _NumberOfElement; i++)
//	{
//
//	}
//}

template<typename T>
void Print(T* Numbers, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << Numbers[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{
	float Numbers[10] = { 10.1f, 6.1f, 4.1f, 3.1f, 5.1f, 7.1f, 9.1f, 1.1f, 2.1f, 8.1f };
	float IntNumbers[10] = { 10, 6, 4, 3, 5, 7, 9, 1, 2, 8 };

	Print<float>(Numbers, 10);
	Print<int>(IntNumbers, 10);
	/*void (*FunctionPointer)();
	FunctionPointer = A;*/
	//Sort(Less);
	
	return 0;
}