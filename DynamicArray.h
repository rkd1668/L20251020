#pragma once
#include "DynamicArray.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray()
	{

	};
	virtual ~TDynamicArray()
	{

	};

	T* Data = nullptr;

	int Size = 0;
	int Capacity = 0;

	int Index = 0;

	void PushBack(T Value)
	{
		if (Index < Capacity)
		{
			Data[Index] = Value;
			Index++;
			Size++;
		}
		else
		{
			if (Capacity == 0)
			{
				Capacity = 1;
			}
			int* TempData = new int[Capacity * 2];
			//배열의 사이즈를 늘린다.
			for (int i = 0; i < Size; i++)
			{
				TempData[i] = Data[i];
			}

			memcpy(Data, TempData, Size * sizeof(int));
			memmove(Data, TempData, Size * sizeof(int));
			if (Data)
			{
				delete[] Data;
			}
			Data = TempData;
			Capacity *= 2;
			Size++;

			Data[Index] = Value;
			Index++;;
		}
	};

	void Print()
	{
		for (int i = 0; i < Index; i++)
		{
			std::cout << Data[i] << std::endl;
		}
	};
};









