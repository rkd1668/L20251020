#include "Engine.h"

using namespace std;

class Singleton
{
protected:
	Singleton()
	{
	}

public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton();
		}
		return Instance;
	}

protected:
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;

//entry point
int main(int argc, char* argv[])
{
	FEngine* MyEngine = new FEngine();

	GEngine = MyEngine;

	/*MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;*/

	return 0;
}