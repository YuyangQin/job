#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int dp[1 << 15][20];
int g[15][15];
int path[1 << 15][15];
int n, m;

void Init()
{
	memset(dp, 0x3f, sizeof(dp));
	memset(g, 0x3f, sizeof(g));
	memset(path, -1, sizeof(path));
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

//递归
void Traveling()
{
	dp[(1 << n) - 1][0] = 0;
	for (int S = (1<<n)-2; S >=0 ; S--)
	{
		for (int u = 0; u < n; u++)
		{
			for (int v = 0; v < n; v++)
			{
				if ((u != 0 && !(S >> u & 1)) || g[u][v] == INF) continue;
				if (!(S>>v&1)&&dp[S][u]>dp[S|1<<v][v]+g[u][v])
				{
					dp[S][u] = dp[S | 1 << v][v] + g[u][v];
					cout << "S=" << bitset<5>(S) << "\t u=" << u << "\tv=" << v << "\tdp[" << bitset<5>(S) << "][" << u
						<< "] = dp[" << bitset<5>(S | 1 << v) << "][" << v << "] + " << g[u][v] << " = " << dp[S][u] << endl;
					path[S][u] = v;
				}
			}
		}
	}
}

void print(int S, int u)
{
	if (S == (1 << n) - 1)
		return;
	int v = path[S][u]; 
	cout << "--->"<<v;
	print(S | 1 << v, v);
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
	Traveling();
	cout << "最短路径：" << 0;
	print(0, 0);
	cout << endl;
	cout << "最短路径长度：" << dp[0][0] << endl;

	return 0;
}
