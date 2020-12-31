#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 200010;
int a[maxn], F[maxn][20],lb[maxn],n,k;

void initlog()
{
	lb[0] = -1;
	for (size_t i = 1; i <= maxn; i++)
	{
		lb[i] = lb[i - 1] + (i&(i - 1) ? 0 : 1);
	}
}

void ST_create()
{
	for (size_t i = 1; i <= n; i++)
	{
		F[i][0] = a[i];
	}
	for (size_t j = 1; j <= lb[n]; j++)
	{
		for (int i = 1; i < n - (1 << j) + 1; i++)
			F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
	}
}

int ST_query(int l, int r)
{
	int kth = lb[r - l + 1];
	return max(F[l][kth], F[r - (1 << kth) + 1][kth]);
}

bool isok(int m)
{
	int t = n / m;
	int ans = 0;
	for (size_t i = 0; i < m; i++)
	{
		ans += ST_query(1 + i*t, t + i*t);
	}
	return ans > k;
}

void compute()
{
	ST_create();
	int l = 1;
	int r = n;
	int ans , mid;
	while (l<=r)
	{
		mid = (l + r) >> 1;
		if (isok(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%d\n", ans);
}

int main()
{
	initlog();
	while (scanf("%d%d",&n,&k), n>=0||k>=0)
	{
		int sum = 0;
		for (size_t i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum<=k)
		{
			printf("-1\n");
		}
		else
		{
			compute();
		}
	}

	return 0;
}
