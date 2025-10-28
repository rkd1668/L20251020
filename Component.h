#pragma once
class AActor;

//추상 클래스
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//순수 가상 함수 -> interface
	virtual void Tick() = 0;

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

