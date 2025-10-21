#include "Engine.h"
#include <iostream>

#include <vector>
#include <list>


//class 설계
//자료구조(STL) 사용


int main(int argc, char* argv[])
{
	std::vector<int> V;
	V.push_back(1);
	V.push_back(2);
	V.push_back(3);

	//for (std::vector<int>::iterator i = V.begin(); i != V.end(); i++)
	for (auto i = V.begin(); i != V.end(); i++)
	{
		std::cout << *i << ", ";
	}
	std::cout << std::endl;

	std::list<int> L;
	L.push_back(2);
	L.push_back(3);
	L.push_back(1);

	L.sort();

	for (auto Data : L)
	{
		std::cout << Data << ", ";
	}
	return 0;
}