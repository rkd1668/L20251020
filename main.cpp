#include "Engine.h"
#include <vector>
#include <iostream>
#include "DynamicArray.h"

using namespace std;


int main(int argc, char* argv[])
{
	TDynamicArray<int> a; 
	for (int i = 0; i < 43; i++)
	{
		a.PushBack(i);
	}

	a.Print();
	return 0;
}