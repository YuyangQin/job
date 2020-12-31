#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int dp[1 << 15][20];
int g[15][15];
int n, m;

void Init()
{
	memset(dp, -1, sizeof(dp));
	memset(g, 0x3f, sizeof(g));
}

/* 有向图
5 8
0 1 3
0 3 4
1 2 5
2 0 4
2 3 5
3 4 3
4 0 7
4 1 6
*/

//记忆化递归
int Traveling(int S, int u)
{
	if (dp[S][u] >= 0)
	{
		return dp[S][u];
	}
	if (S==(1<<n)-1&&u==0)
	{
		return dp[S][u] = 0;
	}
	int ans = INF;
	for (int v = 0; v < n; v++)
	{
		if (!(S >> v & 1) && g[u][v] != INF)
			ans = min(ans, Traveling(S|1<<v,v) + g[u][v]);
	}
	return dp[S][u] = ans;
}

int main()
{
	int u, v, w;
	cin >> n >> m;
	Init();
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		//g[u][v] = g[v][u] = w;无向图
		g[u][v] = w;//建立有向图
	}
	

	cout << "最短路径长度：" << Traveling(0,0) << endl;

	return 0;
}
