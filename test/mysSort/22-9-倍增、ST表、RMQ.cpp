#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//在O(nlogn)的时间建表，在O(1)的时间查询
//主要用于最值查询问题
const int maxn = 10010;
int a[maxn], F[maxn][maxn],n;

void ST_Create()
{
	int k = log2(n);
	for (int i = 1; i <= n; i++)
	{
		F[i][0] = a[i];
	}
	for (size_t j = 1; j <= k; j++)
	{
		for (int i = 1; i <= n - (1 << j) + 1; i++)
		{
			F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int ST_Query(int i, int j)
{
	int k = log2(j - i + 1);
	return max(F[i][k], F[j - (1 << k) + 1][k]);
}

void ST_Print()
{
	int k = log2(n);
	for (size_t j = 0; j <= k; j++)
	{
		for (int i = 1; i <= n - (1 << j) + 1; i++)
		{
			cout << F[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> n;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> a[i];//5 3 7 2 12 1 6 4 8 15
	}
	ST_Create();
	ST_Print();
	cout << "输出查询的区间l,r:" << endl;
	int l, r;
	cin >> l>> r;
	cout << ST_Query(l, r) << endl;

	return 0;
}
