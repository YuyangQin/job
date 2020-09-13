#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//����ʽ
//���ú���ʱ��ʵ��
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

//����ʽ
//����ʱ�Ѿ�����
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
		cout << "������ͬһ��ʵ��" << endl;
	}

	else {
		cout << "?�߲���ͬ?��ʵ��" << endl;
	}
	cout << "----------		���� �� ����ʽ	------------" << endl;
	Singleton2	*	singer3 = Singleton2::getInstance();
	cout << singer3->getCount() << endl;
	Singleton2	*	singer4 = Singleton2::getInstance();
	cout << singer4->getCount() << endl;

	if (singer3 == singer4) {
		cout << "?����ͬ?��ʵ��" << endl;
	}

	else {
		cout << "?�߲���ͬ?��ʵ��" << endl;
	}

	return 0;
}
