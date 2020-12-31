#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//静态算法

const int maxn = 40005;
int n, m, head[maxn], dis[maxn], cnt;
int fa[maxn], ans[maxn];
bool vis[maxn];
vector<int> query[maxn], query_id[maxn];//查询及编号
struct Edge
{
	int to, c, next;
}e[maxn << 1];

void add(int u,int v,int w)
{
	e[++cnt].to = v;
	e[cnt].c = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void add_query(int x, int y, int id)
{
	query[x].push_back(y);
	query_id[x].push_back(id);
	query[y].push_back(x);
	query_id[y].push_back(id);
}

int find(int x)//并查集找祖宗
{
	if (x==fa[x])
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}

void tarjan(int u)
{
	vis[u] = 1;
	for (size_t i = head[u]; i ; i=e[i].next)
	{
		int v = e[i].to;
		int w = e[i].c;
		if (vis[v])
			continue;
		dis[v] = dis[u] + w;
		tarjan(v);
		fa[v] = u;
	}
	for (size_t i = 0; i < query[u].size(); i++)
	{
		int v = query[u][i];
		int id = query_id[u][i];
		if (vis[v])
		{
			int lca = find(v);
			ans[id] = dis[u] + dis[v] - 2 * dis[lca];
		}
	}
}

int main()
{
	int x, y, T, lca;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (size_t i = 1; i <= n; i++)
		{
			head[i] = vis[i] = dis[i] = 0;
			fa[i] = i;
			query[i].clear();
			query_id[i].clear();
		}
		cnt = 0;
		int z;
		for (size_t i = 1; i < n; i++)
		{
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		for (size_t i = 1; i <= m; i++)
		{
			cin >> x >> y;
			if (x==y)
		 	{
				ans[i] = 0;
			}
			else
			{
				add_query(x, y, i);
			}
		}
		tarjan(1);
		for (size_t i = 1; i <= m; i++)
		{
			cout << ans[i] << endl;
		}
	}

	return 0;
}
