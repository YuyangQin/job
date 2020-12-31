#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int maxn = 10010;

int n;


int lowbit(int x)
{
	return (-x)&x;
}


#ifndef false
//一维树状数组
//单点添加
int a[maxn], c[maxn];
void add(int i, int z)//在位置i增加a[i]
{
	for (; i <= n; i += lowbit(i))
	{
		c[i] += z;
	}
}

//求1~i的和
int sum(int i)
{
	int ans = 0;
	for (; i > 0; i -= lowbit(i))
	{
		ans += c[i];
	}
	return ans;
}

//求区间和
int sum(int i, int j)
{
	return sum(j) - sum(i - 1);
}
#else
//多维树状数组
int a[maxn][maxn], c[maxn][maxn];

void add(int x, int y, int z)
{
	for (int i=x; i <= n; i += lowbit(i))
	{
		for (size_t j = y; j <= n; j+-lowbit(j))
		{
			c[i][j] += z;
		}		
	}
}
//求(1,1)到(x,y)的和
int sum(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			ans += c[i][j];
	return ans;
}
//求区间和(x1,y1)到(x2,y2)的区间和
int sum(int x1, int y1, int x2, int y2)
{
	return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}
#endif // 0



int main()
{
	cout << "请输入数组长度n: " << endl;
	cin >> n;
	cout << "请输入数组: " << endl;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(i, a[i]);
	}
	cout << "请输入想求和的数量i: " << endl;
	int i,j;	
	cin >> i;
	cout << sum(i) << endl;
	cout << "请输入想求和的区间i，j：" << endl;
	cin >> i >> j;
	cout << sum(i, j) << endl;
	cout << "请输入想增加的i以及z值: " << endl;
	cin >> i >> j;
	add(i, j);
	cout << "请输入想求和的数量i: " << endl;
	cin >> i;
	cout << sum(i) << endl;

	return 0;
}
