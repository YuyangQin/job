#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 260;

int a[maxn][maxn], lgb[maxn], FMAX[maxn][maxn][10], FMIN[maxn][maxn][10];
int n,b;

void initlog()
{
	lgb[0] = -1;
	for (size_t i = 1; i <= maxn; i++)
	{
		lgb[i] = lgb[i - 1] + (i&(i - 1) ? 0 : 1);
	}
}

void ST_create()
{
	for (size_t k = 1; k <= n; k++)
	{
		for (size_t i = 1; i <= n; i++)
		{
			FMAX[k][i][0] = a[k][i];
			FMIN[k][i][0] = a[k][i];
		}
	}

	for (size_t k = 1; k <= n; k++)
	{
		for (int j = 1; j <= lgb[n]; j++)
		{
			for (size_t i = 1; i <= n-(1<<j)+1; i++)
			{
				FMAX[k][i][j] = max(FMAX[k][i][j - 1], FMAX[k][i + (1 << (j - 1))][j - 1]);
				FMIN[k][i][j] = min(FMIN[k][i][j - 1], FMIN[k][i + (1 << (j - 1))][j - 1]);
			}
		}
	}
}

void solve(int x, int y)
{
	int t = lgb[b];
	int i = y, j = y + b - 1;
	int l = INT_MAX;
	int m = -1;
	for (size_t k = x; k < x+b; k++)
	{
		m = max(m, max(FMAX[k][i][t], FMAX[k][j - (1 << t)+1][t]));
		l = min(l, min(FMIN[k][i][t], FMIN[k][j - (1 << t)+1][t]));
	}
	printf("%d\n", m - l);
}

int main()
{
	int k;
	initlog();
	while (scanf("%d%d%d", &n, &b, &k)!=EOF)
	{
		for (size_t i = 1; i <= n; i++)
		{
			for (size_t j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		ST_create();
		int x, y;
		for (size_t i = 0; i < k; i++)
		{
			scanf("%d%d", &x, &y);
			solve(x, y);
		}
	}

	return 0;
}
