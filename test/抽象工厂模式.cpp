#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



class AbstractGPU
{
public:
	virtual void display() = 0;
};

class AbstractCPU
{
public:
	virtual void caculate() = 0;
};

class IntelGPU:public AbstractGPU
{
public:
	virtual void display()
	{
		cout << "---IntelGPU" << endl;
	}
};

class IntelCPU :public AbstractCPU
{
public:
	virtual void caculate()
	{
		cout << "Intel CPU" << endl;
	}
};

class NvidiaGPU :public AbstractGPU
{
public:
	virtual void display()
	{
		cout << "Nvidia CPU" << endl;
	}
};

class NvidiaCPU :public AbstractCPU
{
public:
	virtual void caculate()
	{
		cout << "Nvidia GPU!!!" << endl;
	}
};

class	AbstractFactory {
public:
	virtual	AbstractGPU	*	createGPU() = 0;
	virtual	AbstractCPU	*	createCPU() = 0;
};

class IntelFactory :public AbstractFactory
{
public:
	virtual IntelGPU* createGPU()
	{
		return new IntelGPU;
	}
	virtual IntelCPU* createCPU()
	{
		return new IntelCPU;
	}
};

class NvidiaFactory :public AbstractFactory
{
public:
	virtual NvidiaGPU* createGPU()
	{
		return new NvidiaGPU;
	}
	virtual NvidiaCPU* createCPU()
	{
		return new NvidiaCPU;
	}
};


int main()
{
	AbstractFactory* factory;
	AbstractGPU* gpu;
	AbstractCPU* cpu;

	factory = new IntelFactory;
	gpu = factory->createGPU();
	cpu = factory->createCPU();
	gpu->display();
	cpu->caculate();

	delete factory;
	delete gpu;
	delete cpu;

	factory = new NvidiaFactory;
	gpu = factory->createGPU();
	cpu = factory->createCPU();
	gpu->display();
	cpu->caculate();

	return 0;
}
