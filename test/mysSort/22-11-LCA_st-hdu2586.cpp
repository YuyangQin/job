#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

/*
	倍增法创建st表O(nlogn)，查询复杂度为O(logn),而暴力搜索查询复杂度为O(n)，所以当
查询数量较少的时候，光创建表就需要O(nlogn),还不如用暴力求解
*/

const int maxn = 40005;
int n, m, k, F[maxn][20];//F[i][j]代表i向上走2^j步的节点
int head[maxn], dist[maxn], d[maxn], cnt;//头节点，据根节点距离，深度，计数

struct Edge
{
	int to, c, next;//临接点，边权，
}e[maxn<<1];//无向图，故长度乘2

//链式前向星，待了解
void add(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].c = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int u)//求深度，距离，初始化F[v][0]
{
	for (size_t i = head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if (v==F[u][0])
		{
			continue;
		}
		d[v] = d[u] + 1;
		dist[v] = dist[u] + e[i].c;
		F[v][0] = u;
		dfs(v);
	}
}

void ST_create()
{
	for (size_t j = 1; j <= k; j++)
	{
		for (size_t i = 1; i <= n; i++)
		{
			F[i][j] = F[F[i][j - 1]][j - 1];//i先走2^(j-1)步到达F[i][j - 1]，再走2^(j-1)到达F[i][j]
		}
	}
}

int LCA_ST_query(int x, int y)
{
	if (d[x]>d[y])
	{
		swap(x, y);
	}
	for (int i = k; i >=0 ; i--)//y向上走到与x同一深度
	{
		if (d[F[y][i]] >= d[x])
			y = F[i][i];
	}
	if (x == y)
		return x;
	for(int i=k;i>=0;i--)//x,y一起向上走
		if (F[x][i]!=F[y][i])
		{
			x = F[x][i];
			y = F[y][i];
		}
	return F[x][0];//返回x的父亲
}

int main()
{
	int x, y, T, lca;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		k = log2(n);
		for (int i = 1; i <= n; i++)//初始化
			head[i] = d[i] = dist[i] = 0;
		cnt = 0;
		for (size_t i = 1; i < n; i++)//输入一棵树的n-1条边
		{
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		d[1] = 1;
		dfs(1);
		ST_create();
		for (size_t i = 1; i <= m; i++)
		{
			cin >> x >> y;
			lca = LCA_ST_query(x, y);
			cout << dist[x] + dist[y] - 2 * dist[lca] << endl;
		}
	}

	return 0;
}