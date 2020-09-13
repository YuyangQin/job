#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//关键头文件
#include <iomanip>

using namespace std;

//控制宽度
void test1()
{
	int a,b,c;
	cout << setiosflags(ios::left);
	while (cin>>a>>b>>c)
	{
		cout << setw(8) << a;
		cout << setw(8) << b;
		cout << setw(8) << c;
	}
}

//控制精度
//加fixed为小数位数，不加为总位数
void test2()
{
	float a=3.1415926;
	cout <<fixed<< setprecision(3) << a;
}

//综合
void test3()
{
	char a;
	int b;
	float c;
	double d;
	while (cin >> a >> b >> c >> d)
	{
		cout << a << " ";
		cout << setw(4) << b << " ";
		cout << fixed << setprecision(2) << c << " ";
		cout << fixed << setprecision(12) << d << " ";
	}
}

int main()
{
	test3();

	return 0;
}
