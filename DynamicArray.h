#pragma once
#include "DynamicArray.h"
#include <iostream>
#include <string.h>
#include <stdio.h>


//compile 할때 코드 생성, 에러가 예측이 됨.
template<typename T>
class TDynamicArray
{
public:
	TDynamicArray()
	{

	};

	//deep copy
	//copy constructor(복사 생성자)
	TDynamicArray(const TDynamicArray<T>& RHS) 
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;

		this->CurrentIndex = RHS.CurrentIndex;

		this->Data = new T[Capacity];
		memmove(RHS.Data, RHS.Data, Size * sizeof(int));
	}

	TDynamicArray<T>& operator=(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;

		this->CurrentIndex = RHS.CurrentIndex;

		this->Data = new T[Capacity];
		memmove(RHS.Data, RHS.Data, Size * sizeof(int));
		return *this;
	}

	virtual ~TDynamicArray()
	{
		if (Data)
		{
			delete[] Data;
		}
	};

protected:
	T* Data = nullptr;

	size_t Size = 0;
	size_t Capacity = 0;

	int CurrentIndex = 0;

public:
	size_t GetSize()
	{
		return Size;
	}

	size_t GetCapacity()
	{
		return Capacity;
	}

	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}

	void PushBack(T Value)
	{
		if (CurrentIndex < Capacity)
		{
			Data[CurrentIndex] = Value;
			CurrentIndex++;
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
			//for (size_t i = 0; i < Size; i++)
			//{
			//	TempData[i] = Data[i];
			//}

			memcpy(TempData, Data, Size * sizeof(int));
			//memmove(TempData, Data, Size * sizeof(int));
			if (Data)
			{
				delete[] Data;
			}
			Data = TempData;
			Capacity *= 2;
			Size++;

			Data[CurrentIndex] = Value;
			CurrentIndex++;
		}
	};

	//void Print()
	//{
	//	for (int i = 0; i < CurrentIndex; i++)
	//	{
	//		std::cout << Data[i] << std::endl;
	//	}
	//};
};









