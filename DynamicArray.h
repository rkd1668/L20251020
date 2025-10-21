#pragma once
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	int* Array;
	int Data[10];

	int Size = 10;

	int Index = 0;

	void PushBack(int Value);

	void Print();
};

