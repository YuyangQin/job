#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100010;
int a[maxn], lg[maxn], F[maxn][20], n;

void Initlog()
{
	lg[0] = -1;
	for (size_t i = 1; i < maxn; i++)
	{
		if (i&(i - 1))
			lg[i] = lg[i - 1];
		else
			lg[i] = lg[i-1] + 1;
	}
}

void ST_create()
{
	for (size_t j = 1; j <= lg[n]; j++)
	{
		for (int i = 1; i <= n - (1 << j)+1; i++)
		{
			F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int ST_query(int l, int r)
{
	if (l>r)
	{
		return 0;
	}
	int k = lg[r - l + 1];
	return max(F[l][k], F[r - (1 << k) + 1][k]);
}


int main()
{
	int q,l,r,k;
	Initlog();

	while (cin >> n&&n != 0)
	{
		cin >> q;
		for (size_t i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (i==1)
			{
				F[i][0] = 1;
				continue;
			}
			if (a[i]==a[i-1])
			{
				F[i][0] = F[i-1][0] + 1;
			}
			else
			{
				F[i][0] = 1;
			}
		}
		ST_create();
		for (size_t i = 0; i < q; i++)
		{
			scanf("%d%d", &l, &r);
			k = l;
			while (k<=r&&a[k]==a[k-1])
			{
				k++;
			}
			cout << max(k - l , ST_query(k, r)) << endl;
		}
	}

	return 0;
}
