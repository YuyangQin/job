#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define N 100
int father[N];

int m, n;//n为节点数，m为边数

void Init()
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
}
//查找
int Find(int x)
{
	if (x!=father[x])
	{
		father[x] = Find(father[x]);
	}
	return father[x];
}
//合并
void Union(int a, int b)
{
	int u = Find(a);
	int v = Find(b);
	if (u!=v)
	{
		father[u] = v;
	}
}

int main()
{
	int u, v, sum = 0;
	cout << "输入n和m：" << endl;
	cin >> n >> m;
	cout << "输入边：" << endl;
	Init();
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v;
		Union(u, v);
	}
	for (size_t i = 1; i <= n; i++)
	{
		Find(i);
		cout << father[i] << " ";
		if (i==father[i])
		{
			sum++;
		}
	}
	cout << endl;
	cout << "sum = " << sum << endl;//共有多少个族群

	return 0;
}

/*
10 9
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
*/
