#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//懒汉式
//调用函数时才实现
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (instance==NULL)
		{
			instance = new Singleton;
		}
		m_count++;
		return instance;
	}
	int getCount()
	{
		return m_count;
	}
private:
	Singleton()
	{
		instance = NULL;
		m_count = 0;
	}
	static Singleton* instance;
	static int m_count;
};
Singleton* Singleton::instance = NULL;
int Singleton::m_count = 0;

//饿汉式
//编译时已经创建
class Singleton2
{
public:
	static Singleton2* getInstance()
	{
		m_count++;
		return instance;
	}
	int getCount()
	{
		return m_count;
	}
private:
	Singleton2()
	{
		instance = NULL;
		m_count = 0;
	}
	static Singleton2* instance;
	static int m_count;
};
Singleton2* Singleton2::instance = new Singleton2;
int Singleton2::m_count = 0;

int main()
{	
	Singleton	*	singer = Singleton::getInstance();
	cout << singer->getCount() << endl;
	Singleton	*	singer2 = Singleton::getInstance();
	cout << singer2->getCount() << endl;

	if (singer == singer2) {
		cout << "两者是同一个实例" << endl;
	}

	else {
		cout << "?者不是同?个实例" << endl;
	}
	cout << "----------		以下 是 饿汉式	------------" << endl;
	Singleton2	*	singer3 = Singleton2::getInstance();
	cout << singer3->getCount() << endl;
	Singleton2	*	singer4 = Singleton2::getInstance();
	cout << singer4->getCount() << endl;

	if (singer3 == singer4) {
		cout << "?者是同?个实例" << endl;
	}

	else {
		cout << "?者不是同?个实例" << endl;
	}

	return 0;
}
