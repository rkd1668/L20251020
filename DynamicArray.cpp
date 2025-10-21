#include "DynamicArray.h"
#include <iostream>
TDynamicArray::TDynamicArray()
{
	Array = Data;
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (Index < Size)
	{
		Array[Index] = Value;
		Index++;
	}
	else
	{
		int* TempData = new int[Size * 2];
		//배열의 사이즈를 늘린다.
		for (int i = 0; i < Size; i++)
		{
			TempData[i] = Array[i];
		}
		Array = TempData;
		Size *= 2;
		Array[Index] = Value;
		Index++;
	}
}

void TDynamicArray::Print()
{
	for (int i = 0; i < Index; i++)
	{
		std::cout << Array[i] << std::endl;
	}
}


