#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 50010;
int num[maxn], MAX[maxn][20], MIN[maxn][20], n, q;

int log2(int k)
{
	int res = log((double)k) / log((double)2);
	return res;
}
void ST_create()
{
	for (size_t i = 1; i <= n; i++)
	{
		MAX[i][0] = num[i];
		MIN[i][0] = num[i];
	}
	int k = log2(n);
	for (size_t j = 1; j <= k; j++)
	{
		for (size_t i = 1; i <= n-(1<<j)+1; i++)
		{
			MAX[i][j] = max(MAX[i][j - 1], MAX[i + (1 << j - 1)][j - 1]);
			MIN[i][j] = min(MIN[i][j - 1], MIN[i + (1 << j - 1)][j - 1]);
		}
	}
}

int ST_query(int l, int r)
{
	int k = log2(r - l + 1);
	int m = max(MAX[l][k], MAX[r - (1 << k) + 1][k]);
	int L = min(MIN[l][k], MIN[r - (1 << k) + 1][k]);
	return m - L;
}

int main()
{
	cin >> n >> q;
	for (size_t i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
	}
	ST_create();
	int l, r;
	for (size_t i = 0; i < q; i++)
	{
		scanf("%d%d", &l, &r);
		cout << ST_query(l, r) << endl;
	}    

	return 0;
}
