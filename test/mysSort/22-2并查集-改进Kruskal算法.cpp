#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

#define N 100
int father[N];
int m, n;//n为节点数，m为边数

struct Edge
{
	int u;
	int v;
	int w;
}e[N*N];//边，有向图数量为，无向图为n*(n-1)/2

bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}

void Init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
}
//查找
int Find(int x)
{
	if (x != father[x])
	{
		father[x] = Find(father[x]);
	}
	return father[x];
}
//合并
int Union(int a, int b)
{
	int u = Find(a);
	int v = Find(b);
	if (u==v)
	{
		return 0;
	}
	if (u > v)
	{
		father[u] = v;
	}
	else
	{
		father[v] = u;
	}
	return 1;
}

int Kruscal(int n)
{
	int ans = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (Union(e[i].u, e[i].v))
		{
			ans += e[i].w;
			n--;
			if (1==n)
			{
				return ans;
			}
		}
	}
	return 0;
}

int main()
{
	int sum = 0;
	cout << "输入节点数n和边数m：" << endl;
	cin >> n >> m;
	cout << "输入节点u,v和边权w：" << endl;
	Init(n);
	for (size_t i = 0; i < m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e, e + m, cmp);
	int ans = Kruscal(n);
	cout << "最小花费为： " << ans << endl;

	for (size_t i = 1; i <= n; i++)
	{
		Find(i);
		cout << father[i] << " ";
		if (i == father[i])
		{
			sum++;
		}
	}
	cout << endl;
	cout << "sum = " << sum << endl;//共有多少个族群

	return 0;
}

/*
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
*/
