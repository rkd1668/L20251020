#pragma once
class UWorld;

class FEngine
{
protected:
	FEngine();

public:
	virtual ~FEngine();

	virtual void Init();
	virtual void Run();
	virtual void Term();

	__forceinline UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return KeyCode;
	}

protected:
	void Input();
	void Tick();
	void Render();

	UWorld* World;

	bool bIsRunning = true;

	int KeyCode = 0;

public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

protected:
	static FEngine* Instance;
};

//extern FEngine* GEngine;

#define GEngine		FEngine::GetInstance()