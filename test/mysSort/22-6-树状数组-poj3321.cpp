#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int maxn = 100010;
int n, a[maxn], c[maxn], fa[maxn];

//有问题，待改进
//可用dfs找出范围，使用树状数组求区间和

void Init()
{
	for (size_t i = 1; i <= n; i++)
	{
		a[i] = 1;
		c[i] = 1;
	}
	fa[1] = 0;
}

void add(int i,int z)
{
	for (;  i>0; i=fa[i])
	{
		c[i] += z;
	}
}

int sum(int x)
{
	int s = 0;
	return c[x];
}

int main()
{
	cin >> n;
	Init();
	int u, v;
	for (size_t i = 1; i < n; i++)
	{
		cin >> u >> v;
		fa[v] = u;
		add(u, 1);
	}
	int m;
	char command;
	cin >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> command >> u;
		if (command=='Q')
		{
			cout << sum(u) << endl;
		}
		else
		{
			if (a[u]==1)
			{
				a[u] == 0;
				add(u, -1);
			}
			else
			{
				a[u] == 1;
				add(u, 1);
			}
		}
	}

	return 0;
}
/*
5
1 3
1 2
3 5
3 4
3
Q 1
C 2
Q 3
*/