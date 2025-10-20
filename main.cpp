#include "Engine.h"

using namespace std;

class Singleton
{
private:
	Singleton()
	{

	}
public:
	Singleton* GetInstance()
	{
		return this;
	};

	static int Gold;

};
//entry point
int main(int argc, char* argv[])
{
	FEngine* MyEngine = new FEngine();

	GEngine = MyEngine;

	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}