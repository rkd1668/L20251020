#pragma once
class AActor;

//�߻� Ŭ����
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//���� ���� �Լ� -> interface
	virtual void Tick() = 0;

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

